#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhaint.h"
#include "loop.h"

int loop(){
    //0 1 2 3 4 5 6 7 8 9 + - * / C E
    pilha p;
	inicia(&p);
    int stop = 0;
    char g_char[200];
    while(!stop){
        printf("\n\n>> POLISH CALCULATOR <<\n");
        printf("> Opcoes <\n\n");
        printf("S - sair\n\n");
        fflush(stdin);
        gets(g_char);
        printf("%s\n", g_char);
        
        //define a saida do programa
        char sair_s[] = "s";
        char sair_S[] = "S";
        if(!strcmp(g_char, sair_S) || !strcmp(g_char, sair_s)){
            stop = 1;
            return 1;
        }
        
        
    }
    
	//insertNum(&p, 7);
	//printf("%d \n\n", getNum(&p));
}
