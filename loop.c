/* 
 *
 * Date: 		02/10/2015
 *
 * Description: Função que contem o loop principal do programa Polish Calculator
 *
 * Authors:	 	name: Allan Ribeiro da Costa
 *				uri: https://github.com/allan074
 *				e-mail: <email>
 *
 *         		name: Marcos Vinicius Volpato
 * 				uri: https://github.com/marcosvolpato
 *				e-mail: volpatomv@gmail.com
 *
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pilhaNum.h"
#include "loop.h"
#include "faz_calculo.h"
#define MAX_LENTH 200
#define RUN_CODES 0

void exibeHeader();
void exibeHelp();
void tiraEspaco(char str[]);

int loop(){
	
	//inicia a pilha usada pelo programa
    pilha *p = inicia();
    char g_char[MAX_LENTH];
    
    //exibe o cabeçalho do programa
    if(!RUN_CODES)
    	exibeHeader();
    
    //loop principal
    while(1){
        gets(g_char);
        if(strlen(g_char) > 1)
        	tiraEspaco(g_char);
        	
        //define a saida do programa
        char sair_s[] = "s";
        char sair_S[] = "S";
        if(!strcmp(g_char, sair_S) || !strcmp(g_char, sair_s))
            return 1;
            
        //define a entrada em help
        char help_h[] = "h";
        char help_H[] = "H";
        if(!strcmp(g_char, help_h) || !strcmp(g_char, help_H)){
        	if(!RUN_CODES)
        		exibeHelp();
        	fflush(stdin);
        	continue;
		}
        
        //entra na função que trata cada char da string informada pelo usuario
        int erro = calcular(g_char, p);
        if(erro == 1){
        	if(!RUN_CODES){
        		exibeHeader();
        		printf("\nErro! Para fazer um calculo, inicie com E\n");
			}
		}
    }
    return 1;
}


//função que exibe o cabeçalho
void exibeHeader(){
	system("cls");
	printf("\n\n>> POLISH CALCULATOR <<\n");
    printf("   > Opcoes <\n\n");
    printf("Sair: S\n"); 
    printf("Help: h\n");
    printf("\nDigite uma expressao:\n");
}


//função que exibe o help
void exibeHelp(){
	system("cls");
	printf("\n\n>> POLISH CALCULATOR <<\n");
    printf("   > HELP <\n\n");
    printf("Clear: C\n\n");
    printf("Operacoes:\n");
    printf("'+': soma\n");
    printf("'-': subtracao\n");
    printf("'*': multiplicacao\n");
    printf("'/': divisao\n");
    printf("'!': fatorial\n");
    printf("'^': potencia\n");
    printf("\n\n");
    printf("Obs: Use E para indicar a entrada de um numero\n\n");
    printf("Obs: Apenas inteiros positivos sao permitidos,\n");
    printf("     por tanto, nao use numeros negativos ou de ponto flutuante\n\n");
    printf("Exemplo de expressao( ex: E 9 0 E 2 0 E 1 5 E 1 3 - * E 5 + / )\n");
    printf("\nNas divisoes o dividendo vem primeiro e o divisor depois\n");
    printf("Ex: \"e34e2/\" o resultado eh 17\n\n");
    printf("Na subtracao o numero a ser subtraido vem depois\n");
    printf("Ex: \"e34e20-\" o resultado eh 14\n\n");
    printf("pressione enter para voltar:\n");
    fflush(stdin);
    char tecla;
    //tecla = getchar();
    scanf("%c",&tecla);
    system("cls");
    exibeHeader();
}

//recebe um char e retorna verdadeiro se esse charfor um numero
int isNum(char c){
	return(c > 47 && c < 58);
}

//recebe um char e retorna verdadeiro se esse char for E maiusculo ou minusculo
int isEnter(char c){
	return(c == 'e' || c == 'E');
}

//recebe um char e retorna verdadeiro se esse char for C maiusculo ou minusculo
int isClear(char c){
	return(c == 'c' || c == 'C');
}

//recebe um char e retorna verdadeiro se esse char for V maiusculo ou minusculo
int isConsulta(char c){
	return(c == 'v' || c == 'V');
}

//aqui recebe uma string e são tratados todos os chars para o proposito do programa
int calcular(char g_char[], pilha *p){

	if( isEnter(g_char[0]) || !isEmpty(p)){
		int i = 0;
		
		while(g_char[i] != '\0'){
			
			//insere o estado dos calculos
			if(!isClear(g_char[i]) && !isConsulta(g_char[i])){
				if(isEmpty(p))
					printf("- ");
				consulta_inversa(p);
				printf("\n");
			}
			
			//se for numero insere na pilha
			if(isNum(g_char[i])){
				insertNum(p, g_char[i] - 48);
				
				//se o char anterior tbm for numero faz calculo para fazer dos 2 um numero
				if(isNum(g_char[i-1] )|| isEnter(g_char[i-1]))
					faz_calculo(p);
				else{
					clear_calc(p);
					if(!RUN_CODES){
						exibeHeader();
						printf("\nErro! Voce deve usar necessariamente \'E\' para informar a entrada de um numero\n");
					}
				}
				i++;
				continue;
			}
			
			//se for um E insere 0 na pilha
			if(isEnter(g_char[i])){
        		insertNum(p, 0);
        		i++;
        		continue;
			}
			
			//se for '-' faz uma subtração
			if(g_char[i] == '-'){
				faz_sub(p);
				i++;
				continue;
			}
			
			//se for '+' faz uma adição
			if(g_char[i] == '+'){
				faz_soma(p);
				i++;
				continue;
			}
			
			//se for '/' faz uma divisão
            if(g_char[i] == '/'){
				faz_div(p);
				i++;
				continue;
			}
			
			//se for '*' faz uma multiplicação
            if(g_char[i] == '*'){
				faz_mult(p);
				i++;
				continue;
			}
			
			//se for '^' faz uma potencia
            if(g_char[i] == '^'){
				faz_pow(p);
				i++;
				continue;
			}
			
			//se for '!' faz um fatorial
            if(g_char[i] == '!'){
				faz_fatorial(p);
				i++;
				continue;
			}
			
			//se for C limpa a pilha
			if(isClear(g_char[i])){
				clear_calc(p);
				if(!RUN_CODES){
					exibeHeader();
					printf("\nPilha Vazia\n");
				}
				i++;
				continue;
			}
			
			//se for V faz uma consulta na pilha
			if(isConsulta(g_char[i]) && strlen(g_char) == 1){
				if(!RUN_CODES)
					consulta(p);
				i++;
			}
				
		}
		if(!isConsulta(g_char[i-1]))
			//consulta que exibe a pilha ao contrario
			consulta_inversa(p);
		if(!RUN_CODES)
			printf("\n");
		return 0;
	}else{
		//se o char indice 0 for V exibe a consulta
		if(isConsulta(g_char[0]))
			if(!RUN_CODES)
				consulta(p);
				
		else{
			//se o char indice 0 for C limpa a pilha
			if(isClear(g_char[0]))
				clear_calc(p);
				
			else
				return 1;
		}
	}
		
	
}
void tiraEspaco(char str[]){
	char * c = (char *) malloc(strlen(str)*sizeof(char));
	int i = 0, j = 0;
	char * aux;
	aux = c;
	while(str[i] != '\0'){
		if(str[i] != ' ' && str[i] != '\0' ){
			c[j] = str[i];
			j++;
		}
		i++;
	}
	c[j] = '\0';
	strcpy(str, c);
	free(aux);
}











