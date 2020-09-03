/* 
Nome: Leonardo Ferreira dos Santos, Aula 2:Disciplina Estrutura de Dados
Exercicio 2: Ordenação por pilha
Descrição  : Foram usadas duas pilha, a recebe os números digitados,
             b serve para auxiliar na busca dos números em a e também armazena
             os menores números no seu fundo, aux mantém o menor número que saiu
             de 'a' para 'b'
             
             As fases do algoritmo são as seguintes
             obs: j: controla quantos números já foram posicionados corretamente
                  k: serve para percorrer b de forma a não interferir nos números que já estão ordenados
                  target: faz com que o numero repetido entre e aux e a pilha b seja removido apenas uma vez
                  isso evita bugs/erros caso o usuário digite o mesmo número várias vezes, sem target o loop
                  deletaria vários números o que faria ocorrer erro de pilha vazia
                  
            loop principal: Controla, caso a pilha b esteja completa com todos os números ordenados
            2º loop: desempilha a comparando com aux para obter o menor números, 
                      enquanto o resto é 'salvo' na pilha b
            k recebe j: isso serve para que posteriormente, os valores que já estão ordenados em b
                        não sejam sobrescritos
            desempilha b até ficar vazio:*o que está em b retorna para a, exceto o número repetido em aux
            empilha menor encontrado: o menor número encontrado no loop 2 é empilhado no fundo de b
            j++: isso ocorre para que no próximo loop, o número que foi empilhado na fase anterior não seja removido/desempilhado
                 ou seja, faz b ser acessado uma posição a menos
            loop repete até b estar cheio com os menores números seguintes em ordem crescente
            
            b é desempilhado em a dessa forma pilha 'a' fica de forma decrescente
            escreve cada numero empilhado em 'a'
            
NÃO FOI ENCONTRADO NENHUM BUG DESSE CÓDIGO NO ONLINE GDB... SE ENCONTRAR ALGUM POR FAVOR AVISE...
**************************************************************************************************************/
#include <stdio.h>
#include "pilha.h"

int main()
{
    int target=0;//evita erro de pilha vazia ao tirar numero duplicado na hora de empilhar aux em b
    int aux;//armazena o menor número
    int n;//determina o tamanho da pilha
    int j=0;//conta quantos números já foram ordenados
    int k=0;//impede que números já ordenados no fundo da pilha b sejam perdidos
    printf("Tamanho da pilha:\n");
    scanf("%d",&n);
    
    Pilha a = pilha(n);
    Pilha b = pilha(n);
    
    for(int i;i<n;i++){
        scanf("%d",&aux);
        empilha(aux,a);
	}
	n--;
	//empilha(desempilha(a),b);//*descobrir pq essa linha bugou meu codigo
	while(!cheiap(b)){
	    aux=topo(a);
	    while(!vaziap(a)){//desempilha a em busca do menor número
	        if(topo(a)<aux){
	            aux=topo(a);
	        }
	        empilha(desempilha(a),b);
	    }
	    k=j;//atribuição para ignorar numeros já ordenados em b
	    target=0;
	    while(k<=n){//desempilha b devolta no a para buscar o proximo numero
	        if(aux==topo(b)&&target==0){//evita que o numero em aux seja repetido
	            desempilha(b);
	            target=1;
	        }else{
	            empilha(desempilha(b),a);
	        }
	        k++;
	    }
	    empilha(aux,b);//Aqui é colocado o menor numero encontrado no fundo de b
	    j++;
	}
	
	while(!vaziap(b)){//desempilha b, deixando a pilha a de forma decrescente (fundo para topo)
		empilha(desempilha(b),a);
	}
	while(!vaziap(a)){
		printf("A:%d\n",desempilha(a));
	}
}