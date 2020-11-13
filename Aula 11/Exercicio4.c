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

void ins(Item x, Arv *A){
    if(*A==NULL)*A = arv(NULL,x,NULL);
    else if(x<=(*A)->item)ins(x, &(*A)->esq);
    else ins(x, &(*A)->dir);
}

void exibe_crescente(Arv A){
    if(A!=NULL){
        exibe_crescente(A->esq);
        printf("%d ",A->item);
        exibe_crescente(A->dir);
    }else{
        return;
    }
}

int busca(int x,Arv A){
    if(A==NULL)return NULL;
    if(x==A->item)return 1;
    if(x<A->item)return busca(x,A->esq);
    else busca(x, A->dir);
}
int main(void) {
    Arv I = NULL;
    Item x;
    while( 1) {
        printf("Item? ");
        scanf("%d",&x);
        if( x<0 ) break;
        ins(x,&I);
    }
    exibe_crescente(I);
    printf("Item? ");
    scanf("%d",&x);
    if( busca(x,I) ) puts("Encontrado!");
    else puts("Inexistente!");
    return 0;
}