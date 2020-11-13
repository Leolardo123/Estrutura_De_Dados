#include <stdio.h>
#include <stdlib.h>
typedef int Item;
typedef struct arv{
    struct arv *esq;
    Item item;
    struct arv *dir;
} * Arv;

Arv arv(Arv e, Item x, Arv d){
    Arv n = malloc(sizeof(struct arv));
    n->esq = e;
    n->item = x;
    n->dir = d;
    return n;
}

void exibe(Arv A,int n) {
    if( A==NULL ) return;
    exibe(A->dir,n+1);
    printf("%*s%d\n",3*n,"",A->item);
    exibe(A->esq,n+1);
}

int nos(Arv A){
    if(!A)return 0;
    return nos(A->esq)+nos(A->dir)+1;
}

int soma(Arv A){
    if(A==NULL)return 0;
    return A->item+soma(A->esq)+soma(A->dir);
}

int main(void){
    Arv I = arv(arv(NULL,2,NULL),1,arv(NULL,3,arv(NULL,4,arv(NULL,5,NULL))));
    exibe(I,0);
    printf("\nsoma dos nos da arvore I:\n%d",soma(I));
    return 0;
}