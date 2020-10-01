#include <stdio.h>
#include <string.h>
int palavras(char *c,int n,int i){
    if(i>=strlen(c)){//condição de parada é quando i estiver selecionando uma posição do vetor char que  
        return n;
    }
    printf("Passo:%d\n", i);
    if(c[i]==' '&&c[i-1]!=' '&&i<strlen(c)){
        printf("1 Verdadeiro:\n");
        palavras(c, n + 1, i + 1);
    }else if(i+1>=strlen(c)){
        printf("2 Verdadeiro:%c\n",c);
        if(c[i]!=' '){
            palavras(c, n + 1, i + 1);
        }
    }else{
        palavras(c, n, i + 1);
    }
}
int main(void){
    char c[256];
    printf("Digite a frase:\n");
    gets(c);
    printf("Quantidade de palavras da frase: %d", palavras(&c, 0, 0));
}