#include <stdio.h>
int rlsearch(int x, int v[],int n){
    if(n<0){
        return 0;
    }else{
        if(v[n]==x){
            return 1;
        }else{
            return rlsearch(x,v,n-1);
        }
    }
    return 0;
}
int main(void){
    int v[8] = {19, 27, 31, 48, 52, 66, 75, 80};
    printf("27: %d\n", rlsearch(27, v, 8));
    printf("51: %d\n", rlsearch(51, v, 8));
    return 0;
}