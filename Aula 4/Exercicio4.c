#include <stdio.h>
#include "fila.h"
#include "pilha.h"

int ttm(Fila F,Pilha P){
    int aux,achados,tempo=0;//aux guarda o valor da fila, achados armazena os processos que já foram encontrados, e tempo soma o tempo gasto na organização dos processos
    achados = 1;
    inverte_pilha(P);
    while(!vaziap(P)&&tempo/achados<P->max){
        tempo++;
        aux = desenfileira(F);
        if(aux==topo(P)){
            printf("\nOrdernado o processo:%d", desempilha(P));
            achados++;
        }
        else{
            enfileira(aux, F);
        }
    }
    if(!vaziap(P)){
        printf("\nErro, pilha não tem os mesmos processos que a fila!");
        return -1;
    }
    return tempo;
}

int inverte_pilha(Pilha P){
    Fila F = fila(256);
    while(!vaziap(P)){
        enfileira(desempilha(P), F);
    }
    while(!vaziaf(F)){
        empilha(desenfileira(F), P);
    }
}
int main(void) {
    int n = 0;
    printf("Digite o tamanho da fila de processos\n");
    do{
        scanf("%d", &n);
        if(n<=0){
            printf("Digite um valor maior que zero!\n");
        }
    } while (n <= 0);
    
    Fila F = fila(n);    
    Pilha P = pilha(n);

    int item = 0;//numero do processo

    for (int i = 0; i < n;i++){
        printf("Digite o numero do item '%d' da fila de processos\n", i+1);
        scanf("%d",&item);
        enfileira(item, F);
    }

    for (int i = 0; i < n;i++){
        printf("Digite o numero do item '%d' da pilha que organiza os processos\n", i+1);
        scanf("%d",&item);
        empilha(item, P);
    }

    printf("\n\nTempo total mínimo: %d\n\n", ttm(F, P));    
    destroif(&F);    
    destroip(&P);    
    
    return 0; 
}