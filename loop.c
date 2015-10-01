#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pilhaNum.h"
#include "loop.h"
#include "faz_calculo.h"
#define MAX_LENTH 200

int loop(){
    pilha *p = inicia();
    char g_char[MAX_LENTH];
    printf("\n\n>> POLISH CALCULATOR <<\n");
    printf("   > Opcoes <\n\n");
    printf("Sair: S\n"); 
    printf("Clear: C\n");
    printf("Operacoes: -, +, *, /\n\n");
    printf("Obs: Use E para indicar a entrada de um numero\n\n");
    printf("Digite uma expressao( ex: E 9 0 E 2 0 E 1 5 E 1 3 - * E 5 + / )\n");
    while(1){
    	//system("cls");
        gets(g_char);
         
        //define a saida do programa
        char sair_s[] = "s";
        char sair_S[] = "S";
        if(!strcmp(g_char, sair_S) || !strcmp(g_char, sair_s))
            return 1;
        
        int erro = calcular(g_char, p);
        if(erro == 1)
        	printf("Para fazer um calculo, inicie com E\n");
    }
    return 1;
}

int isNum(char c){
	return(c > 47 && c < 58);
}

int isEnter(char c){
	return(c == 'e' || c == 'E');
}

int isClear(char c){
	return(c == 'c' || c == 'C');
}

int isConsulta(char c){
	return(c == 'v' || c == 'V');
}


int calcular(char g_char[], pilha *p){
	//E 9 0 E 2 0 E 1 5 E 1 3 - * E 5 + /
	if( isEnter(g_char[0]) || !isEmpty(p)){
		int i = 0;
		
		while(g_char[i] != '\0'){
			
			if(!isClear(g_char[i]) && !isConsulta(g_char[i])){
				if(isEmpty(p))
					printf("- ");
				consulta_inversa(p);
				printf("\n");
			}
			
			if(isNum(g_char[i])){
				insertNum(p, g_char[i] - 48);
				if(isNum(g_char[i-1] )|| isEnter(g_char[i-1]))
					faz_calculo(p);
				i++;
				continue;
			}
			if(isEnter(g_char[i])){
        		insertNum(p, 0);
        		i++;
        		continue;
			}
			if(g_char[i] == '-'){
				faz_sub(p);
				i++;
				continue;
			}
			
			if(g_char[i] == '+'){
				faz_soma(p);
				i++;
				continue;
			}
			
            if(g_char[i] == '/'){
				faz_div(p);
				i++;
				continue;
			}
			
            if(g_char[i] == '*'){
				faz_mult(p);
				i++;
				continue;
			}
			if(isClear(g_char[i])){
				clear_calc(p);
				i++;
				continue;
			}
			if(isConsulta(g_char[i]) && strlen(g_char) == 1){
				consulta(p);
				i++;
			}
				
		}
		if(!isConsulta(g_char[i-1]))
		consulta_inversa(p);
		printf("\n");
		return 0;
	}else{
		if(isConsulta(g_char[0]))
				consulta(p);
				
		else{
			if(isClear(g_char[0]))
				clear_calc(p);
				
			else
				return 1;
		}
	}
		
	
}












