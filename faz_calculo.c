/* 
 *
 * Date: 		02/10/2015
 *
 * Description: Função que contem as operações necessarias para tratar os chars 
 *				do programa Polish Calculator
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

#include "pilhanum.h"
#include <stdio.h>
#include <math.h>

//desempilha um numero e soma com outro tbm desempilhado, este vezes 10 e empilha o resultado
int faz_calculo(pilha *p){
	if(!isEmpty(p)){
		int num1 = getNum(p);
		if(isEmpty(p)){
			insertNum(p, num1);
			return 0;
		}
		int num2 = getNum(p);
		int num = num1 + (num2 * 10);
		insertNum(p, num);
	}
	return 0;
}

//desempilha dois numeros, faz a soma entre eles e empilha o resultado
int faz_soma(pilha *p){
	int num = getNum(p) + getNum(p);
	insertNum(p, num);
	return num;
}


//desempilha dois numeros, faz a multiplicação entre eles e empilha o resultado
int faz_mult(pilha *p){
	int num1 = getNum(p);
	if(isEmpty(p)){
		insertNum(p, num1);
		return num1;
	}
	int num2 = getNum(p);
    int num = num1 * num2;
    insertNum(p, num);
	return num;
}

//desempilha dois numeros, divide o segundo desepilhado pelo primeiro e empilha o resultado
int faz_div(pilha *p){
	int num1 = getNum(p), num;
	if(isEmpty(p)){
		insertNum(p, num1);
		return num1;
	}
	int num2 = getNum(p);
    num = num2 / num1;
    insertNum(p, num);
	return num;
}

//desempilha dois numeros, subtrai o primeiro desepilhado do segundo e empilha o resultado
int faz_sub(pilha *p){
	int num1 = getNum(p), num;
	if(isEmpty(p)){
		insertNum(p, num1);
		return num1;
	}
	int num2 = getNum(p);
    num = num2 - num1;
    insertNum(p, num);
	return num;
}

//desempilha dois numeros, eleva o segundo desepilhado ao primeiro e empilha o resultado
int faz_pow(pilha *p){
	int num1 = getNum(p), num;
	if(isEmpty(p)){
		insertNum(p, num1);
		return num1;
	}
	int num2 = getNum(p);
    num = pow(num2, num1);
    insertNum(p, num);
	return num;
}

//desempilha um numero, calcula seu fatorial e empilha o resultado
int faz_fatorial(pilha *p){
	int num = getNum(p), aux;
	if(num != 0){
		aux = num;
		while(aux > 1){
	    	num *= (aux-1);
	    	aux--;
		}
	    insertNum(p, num);
	}else
		num = 1;
	return num;
}

//limpa a pilha
int clear_calc(pilha *p){
	if(!isEmpty(p)){
		while(p->topo->anterior != NULL)
			getNum(p);
		getNum(p);
		return 0;
	}else{
		return 1;
	}
}





