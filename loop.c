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
    while(1){
        printf("\n\n>> POLISH CALCULATOR <<\n");
        printf("> Opcoes <\n\n");
        printf("S - sair\n\n");
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

int calcular(char g_char[], pilha *p){
	//E 9 0 E 2 0 E 1 5 E 1 3 - * E 5 + /
	if(g_char[0] == 'e' || g_char[0] == 'E'){
		
		int i = 0, count = 0;
		
		while(g_char[i] != '\0'){
			//se o caracter for um numero insere ele(observar ascii) incr count
			if(g_char[i] > 47 && g_char[i] < 58){
				insertNum(p, g_char[i] - 48);
				count++;
				if(i == strlen(g_char)-1){
					if(g_char[strlen(g_char)-1] != 'e' && g_char[strlen(g_char)-1] != 'E')
						count = faz_calculo(p, count);
				}
				i++;
				continue;
			}
			
			if(g_char[i] == 'e' || g_char[i] == 'E'){
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












