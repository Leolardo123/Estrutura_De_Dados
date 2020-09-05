/* 
Nome: Leonardo Ferreira dos Santos, Aula 2:Disciplina Estrutura de Dados
Exercicio 1: Coverter expressão infixa para posfixa
Descrição  : Esse programa serve para transformar equações infixas/tradicionais
             em equações posfixas, a razão por tras disso é o aumento na eficiencia
             dos cálculos, pois os computadores executam calculos na forma posfixas
             
             infixa: (3+4)*(8-6)/2
             posfixa: 3 4 + 8 6 - * 2 /
             
             As fases do algoritmo são as seguintes
             1 Entrada: Equação infixa completamente parenteseada, ex: ((3+4)*(8-6)/2)
             2 chamada da função 'posfixa' que recebe a equação infixa como parâmetro
             3 loop para passar a infixa em e[256] para posfixa em s[256]
             4 se e[i] for um digito de 0 a 9, s[j] recebe esse digito e j some se a um
             5 senão, se e[i] for algum dos operadoes ('+,*,- ou /'), esse operador será empilhado em POR
             6 senão, se e[i] for um ')' s[j] recebe o que está empilhado em P e j soma se a um
             7 após a expressão posfixa ser gerada, a mesma é retornada e exibida na template
             
             Vejamos o que ocorre se digitada a seguinte expressão: ((3+4)*(8-6)/2)
             1 digita-se (((3+4)*(8-6))/2)
             2 posfixa("(((3+4)*(8-6))/2)")
             3* loop, i=0,j=0
             4,5,6 retornam falso,e[i]='(',i=0                                      s[]=''       P=''
             4,5,6 retornam falso,e[i]='(',i=1                                      s[]=''       P=''      
             4,5,6 retornam falso,e[i]='(',i=2                                      s[]=''       P=''
             4 retorna verdadeiro,e[i]='3',s[j]='3',j++->1,i=4                      s[]='3'      P=''
             5 retorna verdadeiro,empilha('+',P),i=5                                s[]='3'      P='+'
             4 retorna verdadeiro,e[i]='4',s[j]='4',j++->2,i=6                      s[]='34'     P='+'
             6 retorna verdadeiro,e[i]=')',s[j]=desempilha(P),s[j]='+',j++->3,i=7   s[]='34+'    P=''
             5 "",empilha('*',P),i=8                                                s[]='34+'    P='*'
             4,5,6 retornam falso,e[i]='(',i=8                                      s[]='34+'    P='*'
             4 retorna verdadeiro,e[i]='8',s[j]='8',j++->4,i=9                      s[]='34+8'   P='*'
             5 retorna verdadeiro,empilha('-',P),i=10                               s[]='34+8'   P='*-'
             4 retorna verdadeiro,e[i]='6',s[j]='6',j++->5,i=11                     s[]='34+86'  P='*-'
             6 retorna verdadeiro,e[i]=')',s[j]=desempilha(P),s[j]='-',j++->6,i=12  s[]='34+86-' P='*'
             6 retorna verdadeiro,e[i]=')',s[j]=desempilha(p),s[j]='*',j++->7,i=13  s[]='34+86-*'P=''
             ...
             fim loop, retorna "34+86-*2/"
NÃO FOI ENCONTRADO NENHUM BUG DESSE CÓDIGO NO ONLINE GDB... SE ENCONTRAR ALGUM POR FAVOR AVISE...
**************************************************************************************************************/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

char *posfixa(char *e){
    static char s[256];
    int j = 0;
    Pilha P = pilha(256);
    for(int i=0; e[i]; i++){
        if(isdigit(e[i]))s[j++]=e[i];
        else if(strchr("+*-/",e[i]))empilha(e[i],P);
        else if(e[i]==')')s[j++]=desempilha(P);
        s[j]='\0';
    }
    destroip(&P);
    return s;
}

int main(void){
    char e[256];
    printf("Infixa? ");
    gets(e);
    printf("Posfixa: %s\n", posfixa(e));
    return 0;
}