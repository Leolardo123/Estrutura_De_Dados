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

int main(void){
    Lista I = NULL;
    exibe(I);
    return 0;
}