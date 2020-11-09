#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct no{
    Item item;
    struct no *prox;
} * Lista;

Lista no(Item x,Lista p){
    Lista n = malloc(sizeof(struct no));
    n->item = x;
    n->prox = p;
    return n;
}

void ins(Item x, Lista *L){
    while(*L != NULL && (*L)->item < x){
        L = &(*L)->prox;
    }
    *L = no(x, *L);
}

void ins_sr(Item x,Lista *L){
    while(*L != NULL && (*L)->item <= x){
        if((*L)->item==x){
            printf("O valor %d ja esta na lista!\n", x);
            return;
        }
        L = &(*L)->prox;
    }
    *L = no(x, *L);
}

void exibe(Lista L){
    int i = 0,item=0;
    while(L){
        item = L->item;
        printf("Posicao %d:%d\n", i, item);
        L = L->prox;
        i++;
    }
}

int main(void){
    Lista I = NULL;
    ins(4,&I);
    ins(1,&I);
    ins(3,&I);
    ins(5,&I);
    ins(2,&I);
    exibe(I);
    int x = 0;
    printf("Digite um numero a ser inserido na lista...");
    scanf("%d", &x);
    ins_sr(x,&I);
    exibe(I);
    return 0;
}