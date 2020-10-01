int vetor_crescente(int a[],int i){
    if(i<0){
        return 1;
    }
    if(a[i]<a[i+1]){
        vetor_crescente(a, i - 1);
    }else{
        return 0;
    }
}

int main(){
    int a[256], b,i=0;
    do{
        printf("Digite o tamanho do vetor\n");
        scanf("%d", &i);
    } while (i <= 0);
    printf("Vetor A:\n");
    for (int k = 0; k < i;k++){
        printf("Digite o valor da posicao:%d\n",k);
        scanf("%d", &a[k]);
    }
    if(vetor_crescente(a,i-2)==1){
        printf("O vetor esta em ordem crescente!");
    }else{
        printf("O vetor nao esta em ordem crescente!");
    }
    return 0;
}