#include <stdio.h>
void exibe(int v[],int n){
    for (int i = 0; i < n;i++){
        printf("%d,", v[i]);
    }
    printf("%d\n", v[n]);
}
void intercala(int v[],int p,int m,int u){
    int w[u-p+1];
    int i = p, j = m + 1, k = 0;
    while(i<=m&&j<=u){
        if(v[i]<v[j])   w[k++] = v[i++];
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
    intercala(v, p, m, u);
}
void msort(int v[],int n){
    ms(v, 0, n - 1);
}
int main(void){
    int v[10] = {83, 31, 91, 46, 27, 20, 96, 25, 96, 80};
    msort(v, 10);
    exibe(v, 10);
    return 0;
}