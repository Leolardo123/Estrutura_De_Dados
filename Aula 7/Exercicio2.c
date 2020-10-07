#include <stdio.h>
void troca(int v[],int i,int j){
    int x = v[i];
    v[i] = v[j];
    v[j] = x;
}
void exibe(int v[],int n){
    for (int i = 0; i < n;i++){
        printf("%d,", v[i]);
    }
    printf("%d\n", v[n]);
}
void empurra(int v[],int n){
    for (int j = 0; j < n;j++){
        if(v[j]<v[j+1]){
            troca(v, j, j + 1);
        }
    }
}
int main(void){
    int v[5] = {48,19,31,52,27};
    empurra(v, 4);
    exibe(v, 4);
    return 0;
}