/* 
Nome: Leonardo Ferreira dos Santos, Aula 2:Disciplina Estrutura de Dados
Exercicio 5: Corrigir código usando função strdup
Descrição  : O algoritmo do exercício 4 possui erro ao acessar o valor em Itemp,
             Isso se deve ao fato de que a função malloc em Itemp não pode alocar
             Um vetor char por si só,por essa razão será usada a função strdup que
             aloca o vetor de char num endereço de memória, e esse endereço pode será
             armazenado em Itemp, assim possibilitando o acesso indireto ao vetor char

NÃO FOI ENCONTRADO NENHUM BUG DESSE CÓDIGO NO ONLINE GDB... SE ENCONTRAR ALGUM POR FAVOR AVISE...
**************************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include "pilha.h"

int main(void){
    Pilha P = pilha(5);
    char s[11];
    for(int i=1; i<=3;i++){
        printf("? ");
        gets(s);
        int *str = strdup(s);
        empilha(str,P);
    }
    
    while(!vaziap(P))puts(desempilha(P));
    return 0;
}
