#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "pilha.h"

char *posfixa(char *e){
    static char s[256];
    Pilha P = pilha(256);
    int j=0;
    for(int i=0;e[i];i++){
        if(e[i]=='F'||e[i]=='V')s[j++]=e[i];
        else if(strchr("!&|",e[i]))empilha(e[i],P);
        else if(e[i]==')')s[j++]=desempilha(P);
        s[j]='\0';
    }
    destroip(&P);
    return s;
}

int valor(char *e){
    Pilha P = pilha(256);
    for(int i=0;e[i];i++){
        if(e[i]=='V')e[i]='1';
        if(e[i]=='F')e[i]='0';
    }
    for(int i=0;e[i];i++){
        if( isdigit(e[i]) ) empilha(e[i]-'0',P);
        else{
            int a = desempilha(P);
            int b;
            if(e[i]!='!')b = desempilha(P);
            switch(e[i]){
                case '!':if(a==1)empilha(0,P);else empilha(1,P);break;
                case '|':if(a||b)empilha(1,P);else empilha(0,P);break;
                case '&':if(a&&b)empilha(1,P);else empilha(0,P);break;
            }
        }
    }
    int z = desempilha(P);
    destroip(&P);
    return z;
}

int main(void)
{
    char e[256];
    printf("Digite a expressão booleana parenteseada\n");
    gets(e);
    printf("A expressão posfixa:%s\n",posfixa(e));
    printf("Resultado Final    :%d",valor(posfixa(e)));
    return 0;
}
