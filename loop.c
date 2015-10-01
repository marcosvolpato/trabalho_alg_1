#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pilhaNum.h"
#include "loop.h"
#include "faz_calculo.h"
#define MAX_LENTH 200

int loop(){
    //0 1 2 3 4 5 6 7 8 9 + - * / C E
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
        if(!strcmp(g_char, sair_S) || !strcmp(g_char, sair_s)){
            return 1;
        }
        
        int erro = calcular(g_char, p);
        if(erro == 1){
        	printf("Para fazer um calculo, inicie com E\n");
		}
    }
    return 1;
}
int isNum(char c){
	return(c > 47 && c < 58);
}
int isEnter(char c){
	return(c == 'e' || c == 'E');
}

int calcular(char g_char[], pilha *p){
	//E 9 0 E 2 0 E 1 5 E 1 3 - * E 5 + /
	if( isEnter(g_char[0]) || !isEmpty(p)){
		int i = 0, count = 0;
		
		while(g_char[i] != '\0'){
			if(!isNum(g_char[i]) && !isEnter(g_char[i]) && isNum(g_char[i-1])){
				faz_calculo(p, count);
				count = 0;
			}
			//se o caracter for um numero insere ele(observar ascii) incr count
			if(isNum(g_char[i])){
				insertNum(p, g_char[i] - 48);
				count++;
				if(i == strlen(g_char)-1){
					count = faz_calculo(p, count);
					count = 0;
				}
				i++;
				continue;
			}
			
			if(isEnter(g_char[i])){
        		count = faz_calculo(p, count);
        		insertNum(p, 0);
        		count++;
        		i++;
        		continue;
			}
			
            if(g_char[i] == '-'){
				faz_sub(p);//ver quem subtrai quem
				count = 0;
				i++;
				continue;
			}
			
			if(g_char[i] == '+'){
				faz_soma(p);
				count = 0;
				i++;
				continue;
			}
			
            if(g_char[i] == '/'){
				faz_div(p);//VER NA DESCRIÇÃO DO TRABALHO QUEM DIVIDE QUEM
				count = 0;
				i++;
				continue;
			}
			
            if(g_char[i] == '*'){
				faz_mult(p);
				count = 0;
				i++;
				continue;
			}
			
			if(g_char[i] == 'c' || g_char[i] == 'C'){
				clear_calc(p);
				count = 0;
				i++;
			}
			
			if(g_char[i] == 'v' || g_char[i] == 'V' && strlen(g_char) == 1){
				consulta(p);
				i++;
			}
				
		}
		return 0;
	}else{
		if(g_char[0] == 'v' || g_char[0] == 'V')
				consulta(p);
				
		else{
			if(g_char[0] == 'c' || g_char[0] == 'C')
				clear_calc(p);
				
			else
				return 1;
		}
	}
		
	
}












