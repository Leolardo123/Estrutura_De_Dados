#include <stdio.h>
int suc(int n) { return n + 1; }
int pred(int n) { return n - 1; }

int somadois(int a,int b){
    if(a>0){
        a = pred(a);
        b = suc(b);
        return somadois(a, b);
    }
    return b;
}

int subtraidois(int a,int b){
    if(b>0){
        a = pred(a);
        b = pred(b);
        return subtraidois(a, b);
    }
    return a;
}

int divide_no_meio(int a,int b){
    if(b>0){
        a = pred(a);
        b = pred(b);
        b = pred(b);
        return divide_no_meio(a, b);
    }
    return a;
}

int minimo(int a,int b,int recupera){
    if(a>0){
        if(b>0){
            b = pred(b);
            a = pred(a);
            recupera = suc(recupera);
            return minimo(a, b, recupera);
        }else{
            return somadois(0, recupera);
        }
    }else
    {
        return somadois(0, recupera);
    } 
}

int maximo(int a,int b,int recupera){
    if(a>0){
        if(b>0){
            b = pred(b);
            a = pred(a);
            recupera = suc(recupera);
            return maximo(a, b, recupera);
        }else{
            return somadois(a, recupera);
        }
    }else
    {
        return somadois(b, recupera);
    } 
}

int parimpar(int a){
    if(a>1){
        a = pred(a);
        a = pred(a);
        return parimpar(a);
    }else{
        return a;
    }
}

int main(void){
    int opt ,a, b = 0;
    do{
        printf("\nEscolha uma opcao ");
        scanf("%d",&opt);
        switch(opt){
            case 1:
                scanf("%d%d", &a, &b);
                printf("\nResultado da soma:%d",somadois(a,b));
                break;
            case 2:
                scanf("%d%d", &a, &b);
                printf("\nResultado da subtracao:%d",subtraidois(a,b));
                break;
            case 3:
                scanf("%d", &a);
                printf("\nDuplicado:%d",somadois(a,a));
                break;
            case 4:
                scanf("%d%d", &a, &b);
                printf("\nResultado da divisao:%d",divide_no_meio(a,a));
                break;
            case 5:
                scanf("%d%d", &a, &b);
                printf("\no menor numero:%d",minimo(a,b,0));
                break;
            case 6:
                scanf("%d%d", &a, &b);
                printf("\no maior numero:%d",maximo(a,b,0));
                break;
            case 7:
                scanf("%d", &a);
                if(parimpar(a)==0){
                    printf("Numero e par");
                }else{
                    printf("Numero e impar");
                }
                break;
        }
    } while (opt != -1);
}

