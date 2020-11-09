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
    printf("]\n");
}


int tamanho(Lista I){
    if(I!=NULL){
        return tamanho(I->prox) + 1;
    }else{
        return 0;
    }
}

int soma(Lista I){
    if(I!=NULL){
        return soma(I->prox)+I->item;
    }else{
        return 0;
    }
}

void anexa(Lista *A,Lista B){
    if(!B)return;
    while(*A){
        A = &(*A)->prox;
    }
    *A = B;
}

void destroil(Lista *I){
    while(*I){
        Lista n = *I;
        *I = n->prox;
        free(n);
    }
}

int ultimo(Lista I){
    if(I==NULL){
        printf("\nLista vazia !");
        abort();
    }
    while(I->prox&&I->item){
        I=I->prox;
    }
    return I->item;
}

int pertence(Lista L,Item item){
    while(L){
        if(L->item==item){
            return 1;
        }else{
            L = L->prox;
        }
    }
    return 0;
}

int main(void){
    Lista I = no(3, no(1, no(5, NULL)));
  
    return 0;
}