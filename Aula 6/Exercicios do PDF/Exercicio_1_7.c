#include <stdio.h>
int inverte(char *c,int p,int u){
    char aux[1];
    if(p<u){
        aux[0] = c[p];
        c[p] = c[u];
        c[u]= aux[0];
        return inverte(c, p+1, u-1);
    }else{
        return;
    }
    return;
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
    inverte(&c, p, u);
    printf("Frase final:%s\n",c);
    return 0;
}