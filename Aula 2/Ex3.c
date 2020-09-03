/* 
Nome: Leonardo Ferreira dos Santos, Aula 2:Disciplina Estrutura de Dados
Exercicio 3: Balanceamento de símbolos ({[]})
Descrição  : Esse algoritmo detecta balanceamento na abertura e fechamento de '{}','[]','()'
             Para que o balanceamento seja afirmativo os simbolos precisam abrir e fechar na mesma ordem
             por ex: [({}())[][]({}){()}]
             Em caso negativo temos vários exemplos:
             }{     *Está fechando antes de abrir
             {{}    *Simbolo não possue correspondente
             {!abc} *Caracter/Simbolo que não faz parte do balanceamento
             
             obs: A cadeia digitada é verificada de forma reversa devido ao comportamento da pilha
             {}() -> )(}{ 
             
            As fazes do algoritmo de validação são as seguintes:
            
            Empilhamento    : [({}())[]({})] -> ])}{(][))(}{([ *forma como será retornada
            Verifica Simbolo: topo(a) == '[' portanto verdadeiro
            Desempilhamento até achar par: ])}{(][))(}{([ -> a = ])}{(][))( '}' ,aux = '{' ([ *par é '{}'
            Verificação e remoção        : topo(aux) = '{' , topo(a) = '}' -> aux = ([ , a = ])}{(][))( ,*topo foi removido
            Repetição até vaziap(a)      : *empilhamento
            
            ao fim do loop: retorna verdadeiro, escreve "A expressão está balanceada!"
            
            caso algum dos passos anteriores retorne falso o algoritmo escreve "A expressão está balanceada!", e finaliza

NÃO FOI ENCONTRADO NENHUM BUG DESSE CÓDIGO NO ONLINE GDB... SE ENCONTRAR ALGUM POR FAVOR AVISE...
**************************************************************************************************************/
#include<stdio.h>
#include <stdbool.h>
#include <string.h>
#include"pilha.h"//pilhadechar*
int main(void){
    int n;
    char s[200];
    
    printf("Cadeia de Simbolos:\n");
    scanf("%s",s);
    
    n = strlen(s);
    
    Pilha p   = pilha(n);
    Pilha aux = pilha(n);
    
    int i=0;
    
    while(i<n){
        empilha(s[i],p);
        i++;
    }
    
    if(verifica_balanceamento(p,aux)){
        printf("A expressão está balanceada!");
    }else{
        printf("A expressão não está balanceada!");
    }
    return 0;
}

int verifica_balanceamento(Pilha p,Pilha aux){
    while(!vaziap(p)){
        if(topo(p)=='}'||topo(p)==')'||topo(p)==']'){//pega os simbolos do topo da pilha p
            empilha(desempilha(p),aux);
        }else if(!vaziap(aux)){//Caso seja o espelho do simbolo atual
            if(topo(p)=='['){//caso simbolo encontrado seja espelho do anterior
                if(topo(aux)!=']'){//verifica se anterior realmente corresponde
                    return false;
                }
                desempilha(aux);//ex: {[[]]} -> {[]} -> {}, *remove anterior
                desempilha(p);//remove espelho do anterior, *dessa forma os if's podem pegar os próximos itens
            }else if(topo(p)=='{'){
                if(topo(aux)!='}'){
                    return false;
                }
                desempilha(aux);
                desempilha(p);
            }else if(topo(p)=='('){//{{()()}}->{{()}}->{{}}, * o algoritmo remove os itens internos primeiro,
                if(topo(aux)!=')'){
                    return false;
                }
                desempilha(aux);
                desempilha(p);
            }else{//caso ocorra inversão ex: ({][}) *conchetes estão invertidos
                return false;
            }
        }else{
            return false;
        }
    }
    return true;
}