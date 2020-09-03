/* 
Nome: Leonardo Ferreira dos Santos, Aula 2:Disciplina Estrutura de Dados
Exercicio 1: Inverter palavras de uma frase usando pilhas
Ex: leonardo ferreira dos santos -> odranoel arerref sod sotnas

 ATENÇÃO, ESSE CÓDIGO PODE APRESENTAR BUGS NO ONLINEGDB, POR FAVOR COPIE E USE EM UM COMPILADOR EM SUA MÁQUINA!
**************************************************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"
int main(void)
{
  char s[82];
  char comp[1];
  Pilha P = pilha(82);
  gets(s);
  int i=0;
  while(s[i]!=comp[0])
  {
  	if(s[i]==' '||s[i+1]==comp[0])
  	{
  		while(!vaziap(P))
		{
			printf("%c",desempilha(P));
		}
		printf(" ");
	}else{
		empilha(s[i],P);
	}
    i++;
  }
  destroip(&P);
  return 0;
}