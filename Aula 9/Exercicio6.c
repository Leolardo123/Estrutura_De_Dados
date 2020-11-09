#include <stdio.h>

typedef int Item;

typedef struct no {
    Item item;
    struct no *prox;
} *Lista;

Lista no(Item x, Lista p) {
    Lista n = malloc(sizeof(struct no));
    n->item = x;
    n->prox = p;
    return n;
}

void ins(Item x, Lista *L) {
    while( *L != NULL && (*L)->item < x )
        L = &(*L)->prox;
    *L = no(x,*L);
}

void ins_sr(Item x, Lista *L) {
    while( *L != NULL && (*L)->item <= x ){
        if((*L)->item == x)
            return;
        L = &(*L)->prox;
    }
    *L = no(x,*L);
}

void ins_rec(Item x, Lista *L){
    if( *L != NULL && (*L)->item < x )
        ins_rec(x, L = &(*L)->prox);
    else{
        *L = no(x,*L);
        return;
    }
}

void exibe(Lista L){
    while(L != NULL){
        printf("%d\n",L->item);
        L = L->prox;
    }
}

void exibe_crescente(Lista L){
    if(L != NULL){
        printf("%d\n", L->item);
        exibe_crescente(L = L->prox);
    }else
        return;
}

void exibe_decrescente(Lista L){
    if(L->prox != NULL){
        exibe_decrescente(L->prox);
        printf("%d\n", L->item);
    }else{
        printf("%d\n", L->item);
        return;
    }
}

void rem(Item x,Lista *L){
    while(*L != NULL && (*L)->item < x){
        L = &(*L)->prox;
    }
    if(*L==NULL || (*L)->item > x) return;
    Lista n = *L;
    *L = n->prox;
    free(n);
}

int main()
{
    Lista I = NULL;
    ins_rec(4,&I);
    ins_rec(1,&I);
    ins_rec(3,&I);
    ins_rec(5,&I);
    ins_rec(2,&I);
    exibe(I);
    printf("\nApos remocao...\n");
    rem(3,&I);
    exibe(I);
    return 0;

}



