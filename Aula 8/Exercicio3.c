#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct no{
    Item item;
    struct no *prox;
} *Lista;

Lista no(Item x, Lista p){
    Lista n = malloc(sizeof(struct no));
    n->item = x;
    n->prox = p;
    return n;
}
void exibe(Lista L){
    printf("[");
    while(L!=NULL){
        printf("%d", L->item);
        L = L->prox;
        if(L!=NULL){
            printf(",");
        }
    }
    printf("]");
}


int tamanho(Lista I){
    if(I!=NULL){
        return tamanho(I->prox) + 1;
    }else{
        return 0;
    }
}
int main(void){
    Lista I = no(3, no(5, NULL));//anterior: no(3, no(1,no(5, NULL)))
    exibe(I);
    printf("Tamanho = %d\n", tamanho(I));
    return 0;
}