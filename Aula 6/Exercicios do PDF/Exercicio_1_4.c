#include <stdio.h>
int suc(int n) { return n + 1; }
int pred(int n) { return n - 1; }

//FUNÇÔES DO EXERCICIO 1_3 (lista 2 item 3)
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
//*****************************************************************************

int produto_dos_naturais(int a,int b,int mult){
    if(b>0){
        b = pred(b);
        mult = somadois(mult, a);
        return produto_dos_naturais(a, b, mult);
    }
    return mult;
}

int divisao_dos_naturais(int a,int b,int quo){
    if(a<b){
        return quo;
    }else{
        quo = suc(quo);
        a = subtraidois(a, b);
        return divisao_dos_naturais(a, b, quo);
    }
}

int resto_da_divisao(int a,int b){
    if(a<b){
        return a;
    }else{
        a = subtraidois(a, b);
        return resto_da_divisao(a, b);
    }
}

int exponenciacao(int a,int b,int total){
    if(b>0){
        b = pred(b);
        total = somadois(total, a);
        return exponenciacao(a, b, total);
    }
    return total;
}

int funcao_quadrada(int a){
}

int main(void){
    int opt ,a, b,aux=0;
    do{
        printf("\nEscolha uma opcao ");
        scanf("%d",&opt);
        switch(opt){
            case 1:
                scanf("%d%d", &a,&b);
                printf("Produto dos naturais:%d",produto_dos_naturais(a, b, 0));
                break;
            case 2:
                scanf("%d%d", &a,&b);
                printf("Quociente da divisao:%d",divisao_dos_naturais(a, b, 0));
                break;
            case 3:
                scanf("%d%d", &a,&b);
                printf("Resto da divisao:%d",resto_da_divisao(a, b));
                break;
            case 4:
                scanf("%d%d", &a,&b);
                printf("Resultado da exponenciacao:%d",exponenciacao(a, b, 0));
                break;
            case 5:
                break;
        }
    } while (opt != -1);
}

