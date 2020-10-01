int somatorio_doVetor(int a[],int i){
    if(i<=0){
        return a[0];
    }else{
        a[0]=a[0]+a[i];
        somatorio_doVetor(a, i - 1);
    }
}

int media_vetor(int a[],int i){
    return somatorio_doVetor(a,i-1)/i;
}

int main(){
    int a[256],i=0;
    do{
        printf("Digite o tamanho do vetor\n");
        scanf("%d", &i);
    } while (i <= 0);
    printf("Vetor A:\n");
    for (int k = 0; k < i;k++){
        printf("Digite o valor da posicao:%d\n",k);
        a[k] = 0;
        scanf("%d", &a[k]);
    }
    printf("O media e:%d",media_vetor(a,i));
    return 0;
}