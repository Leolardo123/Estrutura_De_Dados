#include <stdio.h>
void exibe(int v[],int n){
    for (int i = 0; i < n;i++){
        printf("%d,", v[i]);
    }
    printf("%d\n", v[n]);
}
void intercalad(int v[],int p,int m,int u){
    int w[u-p+1];
    int i = p, j = m + 1, k = 0;
    while(i<=m&&j<=u){
        if(v[i]>v[j])   w[k++] = v[i++];
        else w[k++] = v[j++];
    }
    while( i<=m ) w[k++] = v[i++];
    while( j<=u ) w[k++] = v[j++];
    for(k=0; k<=u-p; k++) v[p+k] = w[k];
}
void ms(int v[],int p,int u){
    if(p==u)
        return;
    int m = (p + u) / 2;
    ms(v, p, m);
    ms(v, m + 1, u);
    intercalad(v, p, m, u);
}
void msortd(int v[],int n){
    ms(v, 0, n - 1);
}
int main(void){
    int v[256],n=0;
    do{
        printf("Digite o tamanho do vetor\n");
        scanf("%d", &n);
    } while (n <= 0);
    printf("Digite os valores do vetor:\n");
    for (int j = 0; j < n;j++){
        printf("Valor do item:%d\n", j);
        scanf("%d", &v[j]);
    }
    msortd(v, n);
    exibe(v, n);
    return 0;
}