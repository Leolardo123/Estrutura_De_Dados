int vetores_iguais(int a[],int b[],int i){
    if(i<0){
        return 1;
    }
    printf("i=%d / %d:%d\n", i, a[i], b[i]);
    if(a[i]==b[i]){
        vetores_iguais(a, b, i-1);
    }else{
        return 0;
    }
}

int main(){
    int a[256], b[256],i=0;
    do{
        printf("Digite o tamanho dos vetores\n");
        scanf("%d", &i);
    } while (i <= 0);
    printf("Vetor A:\n");
    for (int k = 0; k < i;k++){
        printf("Digite o valor da posicao:%d\n",k);
        scanf("%d", &a[k]);
    }
    printf("Vetor B:\n");
    for (int k = 0; k < i;k++){
        printf("Digite o valor da posicaoo:%d\n",k);
        scanf("%d", &b[k]);
    }
    if(vetores_iguais(a,b,i-1)==1){
        printf("Os vetores sao iguais!");
    }else{
        printf("Os vetores sao diferentes!");
    }
    return 0;
}