#include <stdio.h>
int soma_digitos(int n){
   if(n>9){
       return (n%10)+soma_digitos(n/10);
   }
   return n;
}
int main(void){
    int n;
    printf("Digite o número para a soma de digitos");
    scanf("%d", &n);
    n=soma_digitos(n);
    printf("O resultado final e igual a :%d", n);
    return 0;
}