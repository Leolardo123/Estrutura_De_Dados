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

void rem_todo(Item x,Lista *L){
    while(*L != NULL){
        if((*L)->item == x){
            Lista n = *L;
            *L = n->prox;
            free(n);
        }else{
            L = &(*L)->prox;
        }
        if((*L)->item > x){
            return;
        }
    }
    
}

int pert(Item x,Lista L){
    while(L != NULL){
        if(L->item == x){
            return 1;
        }
        if(L->item > x){
            return 0;
        }
        L = L->prox;
    }
}

int pert_rec(Item x,Lista L){
    if(L->item == x){
        return 1;
    }else if(L->prox!=NULL){
        return pert_rec(x, L->prox);
    }
    return 0;
}

int main()
{
    Lista I = NULL;
    ins(4,&I); ins(1,&I); ins(3,&I); ins(2,&I);
    printf("%d\n", pert_rec(5, I));
    printf("%d\n", pert_rec(3, I));
    return 0;

}



