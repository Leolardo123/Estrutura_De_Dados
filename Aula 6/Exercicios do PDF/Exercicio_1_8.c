#include <stdio.h>
int palindroma(char *c,int p,int u){
    if(p<u){
        if(c[p]==c[u]){
            return palindroma(c, p+1, u-1);
        }else if(c[p]==" "){
            return palindroma(c, p+1, u);
        }else if(c[u]==" "){
            return palindroma(c, p, u-1);
        }else{
            return 0;
        }
    }else{
        return 1;
    }
}
int main(void){
    int p, u;
    char aux[1];
    char c[256];
    printf("Digite a frase\n");
    gets(c);
    printf("Digite a posicao inicial\n");
    do{
        scanf("%d", &p);
    } while (p < 0);
    printf("Digite a posicao final\n");
    do{
        scanf("%d", &u);
    } while (u <= p);
    if(palindroma(&c, p, u)==1){
        printf("Trecho e palindroma!");
    }else{
        printf("Trecho nao e palindroma!");
    }
    return 0;
}