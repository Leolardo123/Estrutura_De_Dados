#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "fila.h"

#define dim 9
#define cor(i,j) (i>=0&&i<dim&&j>=0&&j<dim?I[i][j]:-1) 
#define par(i,j) ((i)*100+(j))
#define lin(p)   ((p)/100)
#define col(p)   ((p)%100)

int I[dim][dim] = {
        			{0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 1, 0, 0, 0, 0},
					{0, 0, 0, 1, 1, 1, 0, 0, 0},
					{0, 0, 1, 1, 1, 1, 1, 0, 0},
					{0, 1, 1, 1, 1, 1, 1, 1, 0},
					{0, 0, 2, 0, 0, 0, 2, 0, 0},
					{0, 0, 2, 0, 0, 0, 2, 0, 0},
					{0, 0, 2, 2, 2, 2, 2, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0}
				};


void exiba(int I[dim][dim]){
    for (int i = -1; i < dim;i++){
        _textcolor(8);
        for (int j = -1; j < dim;j++){
            if( i<0 && j<0) printf("  ");
            else if( i<0) printf("%2d",j);
            else if( j<0) printf("\n%2d",i);
            else{ 
                _textcolor(I[i][j]);
                printf("%c%c",219,219);
            }
        }
    }
	_textcolor(8);
}

void colorir(int I[dim][dim], int i, int j, int n) {
	Fila F = fila(dim*dim);
	int a = I[i][j];
	I[i][j] = n;
	enfileira(par(i,j),F);
	while( !vaziaf(F) ) {
		int p = desenfileira(F);
		i = lin(p);
		j = col(p);
		if(a != n){
    		if( cor(i-1,j)==a ) { I[i-1][j]=n; enfileira(par(i-1,j),F); }
    		if( cor(i,j+1)==a ) { I[i][j+1]=n; enfileira(par(i,j+1),F); }
    		if( cor(i+1,j)==a ) { I[i+1][j]=n; enfileira(par(i+1,j),F); }
    		if( cor(i,j-1)==a ) { I[i][j-1]=n; enfileira(par(i,j-1),F); }
		}else{
    		printf("\n\n nao e possivel colocar a mesma cor (digite novamente) \n\n");
    		break;
		}
	}
	destroif(&F);
}

void salvar(char *s){
	FILE *arquivo;

	arquivo = fopen(s,"w");

	if(!arquivo){
		printf("Arquivo nao pode ser criado...\n");
		return;
	}
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			fprintf(arquivo,"%d ",I[i][j]);
		}
		fprintf(arquivo,"\n");
	}
	fclose(arquivo);
}

int inicia(char *s){
	FILE *arquivo;

	arquivo = fopen(s,"r");

	if(!arquivo){
		printf("Arquivo nao existe...\n");
		return 0;
	}else{
		printf("imagem anterior:\n");
		exiba(I);
		printf("\n\n\n Imagem Carregada:\n");
	}
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			fscanf(arquivo,"%d ",&I[i][j]);
		}
		fscanf(arquivo,"\n");
	}
	fclose(arquivo);
	return 1;
}

int main(void){
	char s[256];
    int i,j,n=0,opt=0,msg=0;
	do{
		printf("(1)-Abrir como txt\n(2)-Abrir imagem padrão\n(0)-Sair");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("digite o nome do arquivo:");
				scanf("%s",s);
				msg = inicia(s);
				break;
			case 2:break;
			case 0:return 0;break;

		}
	}while(opt!=2&&msg==0);

	do{
		exiba(I);
		printf("\n\n(1) - Nova cor \n(2) - Salvar em txt (ou -1 para sair)? ");
		scanf("%d",&opt);
		if(opt==-1)break;
		switch(opt){
			case 1:
				printf("\ndigite o número da cor");
				scanf("%d",&n);
				do{
					printf("Posicao? ");
					scanf("%d %d", &i,&j);
				}while( i<0 || i>=dim||j<0||j>=dim);
				colorir(I,i,j,n);
			break;
			case 2:
				printf("\ndigite o nome do arquivo");
				scanf("%s",&s);
				salvar(s);
			break;
		}
	}while(n>=0);
    return 0;
}

