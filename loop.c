#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pilhaint.h"
#include "loop.h"
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
        int erro = calcular(g_char);
        if(erro == 1){//até aqui debugado
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
	if(g_char[0] == 'e' || g_char[0] == 'E'){//até aqui debugado
		if(DEBUG)
        	printf("primeiro char eh E\n");//até aqui debugado
		insertNum(p, 0);
		int i = 1, count = 1;
		while(g_char[i] != '\0'){
			if(DEBUG)
        		printf("%s\n", g_char);//até aqui debugado
			//se o caracter for um numero insere ele(observar ascii) incr count
			if(g_char[i] > 47 && g_char[i] < 58){//numero
				insertNum(p, g_char[i] - 47);
				if(DEBUG)//criar var
					printf("\n%d\n", g_char[i] - 47);/////////////TA FALTANDO PASSAR DE NOVO AQUI//////////////
				count++;
			}
			//se for e ou E desempilha enq count > 0 decrementando
			if(g_char[0] == 'e' || g_char[0] == 'E'){//enter////////////////TA CONTANDO O E DENOVO QDO SAI DA PILHA
				if(DEBUG)
        			printf("enter denovo");
				int num = 0;
				int pot = 0;
				while(count > 0){
					num += pow(getNum(p), pot);
					if(DEBUG)
        				printf("\n%d\n", num);
					count--;
					pot++;
				}
				insertNum(p, num);
				printf("\n %d \n", num);
			}
			if(g_char[0] == '-')//operadores
			if(g_char[0] == '+')
			if(g_char[0] == '/')
			if(g_char[0] == '*')
			if(g_char[0] == 'c' || g_char[0] == 'C')//clean
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











