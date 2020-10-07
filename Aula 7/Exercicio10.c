#include <stdio.h>
int rbsearch(int x, int v[],int n,int cont){
    printf("%d\n", cont);
    if(cont>n||cont<0){
        return 0;
    }else{
        if(v[cont]==x){
            return 1;
        }else{
        if(v[cont]<x){
            return rbsearch(x, v, n, cont+1);
        }else{
            return rbsearch(x, v, cont-1, cont-1);
        }
        }
    }
}
int main(void){
    int v[8] = {19, 27, 31, 48, 52, 66, 75, 80};
    int meio = 4;
    printf("27: %d\n", rbsearch(27, v, 8, meio));
    printf("51: %d\n", rbsearch(51, v, 8, meio));
    return 0;
}

