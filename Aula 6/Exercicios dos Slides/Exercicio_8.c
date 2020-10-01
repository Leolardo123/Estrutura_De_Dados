#include <stdio.h>

int count = 0;

void move_discos(int origem, int destino, int auxiliar, int quantidade){
    if( quantidade == 1 ){
        printf("Move de %d para %d\n", origem, destino);
        count+=1;
    }else{
        move_discos(origem, auxiliar, destino, quantidade-1);
        move_discos(origem, destino, auxiliar, 1);
        move_discos(auxiliar, destino, origem, quantidade-1);
    }
}

int main(){
    int quantidade = 0;

    printf("Digite a quantidade de discos");
    do{
        scanf("%d", &quantidade);
    } while (quantidade < 2);

    move_discos(0, 2, 1, quantidade);

    printf("\nQuantidade de Discos: %d\n", quantidade);
    printf("Nº minimo de movimentos: %d\n\n", count);

    return 0;
}