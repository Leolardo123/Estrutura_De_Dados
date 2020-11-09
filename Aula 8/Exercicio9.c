#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "pilha.h"
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

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

Lista cria_lista(Fila valores){//permite criar lista durante execução
    if(!vaziaf(valores)){//Monta a lista recursivamente
        int valor = desenfileira(valores);
        printf("no(%d,",valor);//imprime o nó atual
        return no(valor, cria_lista(valores));//Retorna o item e cria o proximo
    }else{
        printf("NULL");
        int parenteses = valores->max;
        while(parenteses>0){//imprime o fechamento dos parenteses
            printf(")");
            parenteses--;
        }
        printf("\n");
        return NULL;//retorna ultimo item da lista
    }
}//cria_lista, além de criar a lista também imprime o formato dela, ex: no(1,no(2,null))

Lista inverte_crialista(Lista L){//usa o principio da pilha para inverter a lista
    Pilha Inversora = pilha(tamanho(L));
    Fila ListaInvertida = fila(tamanho(L));
    while(!cheiap(Inversora)){
        empilha(L->item, Inversora);
        L = L->prox;
    }
    while(!vaziap(Inversora))enfileira(desempilha(Inversora),ListaInvertida);
    return cria_lista(ListaInvertida);
}

Lista inverte_itens(Lista L){
    Lista aux = L;
    int comeco = 0, final = tamanho(L) - 1;
    while(comeco<final){
        int *no;
        for (int i = 0; i < comeco;i++){
            no = &L->prox->item;
            L = L->prox;
        }
        L = aux;
        for (int i = 0; i < final; i++)
        {
            aux = L->prox;
        }
        *no = aux->item;
        aux = L;
        comeco++;
        final--;
    }
    return L;
}
int main(void){
    int tamanho=0;
    printf("Digite o tamanho da lista encadeada...\n");
    do{
        scanf("%d", &tamanho);
        if(tamanho<=0){
            printf("Digite um valor maior que zero!\n");
        }
    } while (tamanho <= 0);

    Fila valores = fila(tamanho);
    int valor = 0;

    while(!cheiaf(valores)){
        printf("Digite o valor do item %d\n",tamanho);
        scanf("%d", &valor);
        if(!valor){
            printf("digite um valor valido!\n");
        }else{
            enfileira(valor, valores);
            tamanho--;
        }
    }

    Lista I = cria_lista(valores);

    printf("Normal = ");
    exibe(I);
    I = inverte_itens(I);

    printf("Invertida = ");
    exibe(I);
    return 0;
}