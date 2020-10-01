int maximo_doVetor(int a[],int i){
    if(i<0){
        printf("%d\n",a[i + 1]);
        return a[i+1];
    }
    if(a[i]<a[i+1]){
        int aux=a[i+1];
        a[i + 1] = a[i];
        a[i] = aux;
        maximo_doVetor(a, i - 1);
    }else{
        maximo_doVetor(a, i - 1);
    }  
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
    printf("O maior valor e:%d",maximo_doVetor(a,i-2));
    return 0;
}