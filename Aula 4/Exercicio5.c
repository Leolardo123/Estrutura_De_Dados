#include <stdio.h>
#include <string.h>
#include "pilha.h"
#include "fila.h"

int concha(char *c){
    Pilha aux = pilha(256);
    Pilha P = pilha(256);
    if(se_AouB(c)!=1){
        return -1;
    }else{
        for (int i=0; i < strlen(c);i++){
            empilha(c[i], P);
        }
        if(!vaziap){
            empilha(desempilha(P), aux);
        }
            
        while(!vaziap(P)){
            if(!vaziap(P)&&!vaziap(aux)&&topo(P)==topo(aux)){
                printf("\nP:%c Aux:%c", desempilha(P), desempilha(aux));
            }else if(!vaziap(P)){
                empilha(desempilha(P), aux);
            }
        }
        
        if(vaziap(aux)){
   
            return 1;
        }else{
 
            return 0;
        }
        return;
    }
   
}

void filtra(Fila F){
    int result;
    char c[256];
    while(!vaziaf(F)){
        strcpy(c, desenfileira(F));
        result = concha(c);
        if(result==1){
            printf("\nExpressao: %s -> e concha!",c);
        }else if(result==0){
            printf("\nExpressao: %s -> nao e concha!",c);
        }else{
            printf("\nExpressao: %s -> nao e valida!",c);
        }
    }
    return;
}

int se_AouB(char *c){//verifica se os caracteres do item são válidos (A ou B maiusculo)
    for (int i = 0; i < strlen(c);i++){
        if(c[i]!='A'&&c[i]!='B'){
            return 0;
        }
    }
    return 1;
}

int main(void){
    char c[256];
    Fila F = fila(21);    
    enfileira("AAAAAAAABAAABA",F);//exemplos dados no exercicio
    enfileira("BBBBBBBBBBBBBB",F);    
    enfileira("ABBABBABBABB",F);    
    enfileira("AAABAAABBABAAA",F);    
    enfileira("ABAABAAAAAAAAA",F);    
    enfileira("AABAAAAAABAAAA",F);    
    enfileira("AAAABB",F);    
    enfileira("AABBBBAABAAB",F);    
    enfileira("ABAAAAAAAAAB",F);    
    enfileira("ABABBBABAB",F);    
    enfileira("BBBBBBBBBBBBBB",F);    
    enfileira("AABAABAAAA",F);    
    enfileira("AABAAABBBBBABB",F);    
    enfileira("BBBAAAAABA",F);    
    enfileira("BBBBBBBBBBBBBB",F);    
    enfileira("AAAAAAAAAAAABB",F);    
    enfileira("BAAAAABAAAAAAA",F);    
    enfileira("BBBBABBBBBBA",F);    
    enfileira("BBABABAAAAAABB",F);    
    enfileira("ABAABAABAB",F);//exemplos dados no exercicio
    gets(c);//valor colocado pelo usuário para testar expressões inválidas
    int c1 = strdup(c);
    enfileira(c1,F); 
    filtra(F); 
    // deve exibir 12 conchas    
    destroif(&F);    
    return 0; 
}

