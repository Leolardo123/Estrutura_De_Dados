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

int folha(Arv A){
    if(A==NULL)return 0;
    if(A->esq==NULL&&A->dir==NULL)return 1;
    return folha(A->esq)+folha(A->dir);
}   

int altura(Arv A){
    if(A==NULL)return -1;
    if(altura(A->esq)+1>altura(A->dir)+1){
        return altura(A->esq)+1;
    }else{
        return altura(A->dir)+1;
    }
}

Arv clone(Arv A){
    if(A==NULL)return NULL;    
    return arv(clone(A->esq),A->item,clone(A->dir));
}

int pertence(int x,Arv A){
    if(A==NULL)return 0;
    if(A->item==x)return 1;
    if(pertence(x,A->esq)==1||pertence(x,A->dir)==1){
        return 1;
    }  
    return 0;
}

void preordem(Arv A){
    if(A!=NULL){
        printf("%d ",A->item);
        preordem(A->esq);
        preordem(A->dir);
    }else{
        return;
    }
}

void em_ordem(Arv A){
    if(A!=NULL){
        em_ordem(A->esq);
        printf("%d ",A->item);
        em_ordem(A->dir);
    }else{
        return;
    }
}

int main(void){
    Arv I = arv(arv(NULL,2,NULL),1,arv(NULL,3,arv(NULL,4,arv(arv(NULL,6,NULL),5,arv(NULL,7,NULL)))));
    exibe(I,0);
    printf("\nSequencia em ordem da arvore I:\n");
    em_ordem(I);
}