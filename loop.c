#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#include "pilhaint.h"
#include "pilhaNum.h"
#include "loop.h"
#include "faz_calculo.h"
#define MAX_LENTH 200
#define DEBUG 1

int loop(){
    //0 1 2 3 4 5 6 7 8 9 + - * / C E
    pilha p;
	inicia(&p);
    int stop = 0;
    char g_char[MAX_LENTH];
    zerarStr(g_char);
    while(!stop){
        printf("\n\n>> POLISH CALCULATOR <<\n");
        printf("> Opcoes <\n\n");
        printf("S - sair\n\n");
        fflush(stdin);
        gets(g_char);
        if(DEBUG)
        	printf("%s\n", g_char);
        
        //define a saida do programa
        char sair_s[] = "s";
        char sair_S[] = "S";
        if(!strcmp(g_char, sair_S) || !strcmp(g_char, sair_s)){
            stop = 1;
            return 1;
        }
        int erro = calcular(g_char, &p);
        if(erro == 1){
        	printf("Para fazer um calculo, inicie com E\n");
        	return 1;
		}
        	
        
        
    }
    
	//insertNum(&p, 7);
	//printf("%d \n\n", getNum(&p));
}

int zerarStr(char str[]){
	int i;
	for(i=0;i<MAX_LENTH;i++){
		str[i] = '\0';
	}
	return 0;
}

int calcular(char g_char[], pilha *p){
	//E 9 0 E 2 0 E 1 5 E 1 3 - * E 5 + /
	//testar 1º char para ver se é E ou e se for, empilhar 0(só a primeira)
	if(g_char[0] == 'e' || g_char[0] == 'E'){
		if(DEBUG)
        	printf("primeiro char eh E\n");
		insertNum(p, 0);
		int i = 1, count = 1;
		while(g_char[i] != '\0'){
			if(DEBUG)
        		printf("%s\n", g_char);
			//se o caracter for um numero insere ele(observar ascii) incr count
			if(g_char[i] > 47 && g_char[i] < 58){
				insertNum(p, g_char[i] - 48);
				if(DEBUG)//criar var
					printf("\n%d\n", g_char[i] - 48);
				count++;//considerar usar um continue
			}
			//se for e ou E desempilha enq count > 0 decrementando
			if(g_char[i] == 'e' || g_char[i] == 'E' && i != 0){
				if(DEBUG)
        			printf("enter denovo");
        		faz_calculo(p, count);
			}
			if(g_char[strlen(g_char)-1] != 'e' && g_char[strlen(g_char)-1] != 'E' && i == strlen(g_char)-1){
				if(DEBUG)
					printf("\n strlen: %d", strlen(g_char));
				faz_calculo(p, count);
			}
//			if(g_char[0] == '-')//operadores
//			if(g_char[0] == '+')
//			if(g_char[0] == '/')
//			if(g_char[0] == '*')
//			if(g_char[0] == 'c' || g_char[0] == 'C')//clean
			//se for qualquer outro char return 1
			//decidir o que fazer se for limpar
			//
			i++;
		}
		return 0;
	}else{
		return 1;
	}
		
	
}











