#include <stdio.h>

void bin(int num, int i){
    int resto;
    if(num == 0){
        printf("numero de digitos necessarios: %d\n",i);
        printf("numero em binario: ");
        return;
    }
    resto = num % 2;
    num /= 2;
    i++;
    bin(num, i);
    printf("%d",resto);
}

int main()
{
    int num;
    printf("Digite o numero a ser transformado em binario: ");
    scanf("%d", &num);
    bin(num, 0);
    return 0;
}