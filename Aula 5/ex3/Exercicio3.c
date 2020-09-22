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
        			{2, 2, 2, 2, 2, 2, 2, 2, 2},
        			{2, 2, 2, 2, 6, 2, 2, 2, 2},
        			{2, 2, 2, 6, 6, 6, 2, 2, 2},
        			{2, 2, 6, 6, 3, 6, 6, 2, 2},
        			{2, 6, 6, 3, 3, 3, 6, 6, 2},
        			{2, 2, 6, 6, 3, 6, 6, 2, 2},
        			{2, 2, 2, 6, 6, 6, 2, 2, 2},
        			{2, 2, 2, 2, 6, 2, 2, 2, 2},
        			{2, 2, 2, 2, 2, 2, 2, 2, 2}
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

void salvar(int (*I)[dim][dim],char *s){
	scanf("%c",&s);
	FILE *a = fopen(s,"wb");
	if(!a){
		printf("\nArquivo nao pode ser aberto...\n");
		fclose(a);
		return;
	}
	if(!I){
		fclose(a);
		puts("\nErro imagem está vazia!\n");
		fclose(a);
		return;
	}
	fwrite(I, sizeof(int), dim*dim, a);
	if(fread(I, sizeof(int), dim*dim, a) != dim*dim){
		for(int j=0; j<dim; j++) {
    		for(int i=0; i<dim; i++){
        		printf(" %d", I[j][i]);	
			}
			printf("\n");
		}
	}
	fclose(a);
}

void inicia(int (*I)[dim][dim],char *s){
	s = "img.txt";

	FILE *a = fopen(s,"wb");
	if(!a){
		printf("\nArquivo nao encontrado:%s",s);
		abort();
	}
	fread(I, sizeof(float), dim*dim, a);
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			printf(" %d ",&I[i][j]);
		}
		printf("\n");
	}
	fclose(a);
	return;
}

int main(void){
	char s[256];
    int i,j,n=0,opt=0;
	do{
		printf("(1)-Abrir como txt\n(2)-Abrir imagem padrão\n(0)-Sair");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("digite o nome do arquivo:");
				scanf("%s",s);
				inicia(&I,s);
			break;
			case 2:break;
			case 0:return 0;break;

		}
	}while(!I);

	do{
		exiba(I);
		printf("\n\n(1) - Nova cor \n(2) - Salvar em txt (ou -1 para sair)? ");
		scanf("%d",&opt);
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
				scanf("%c",&s);
				salvar(&I,s);
			break;
		}
	}while(n>=0);
    return 0;
}

