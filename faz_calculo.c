#include "pilhanum.h"
#include <stdio.h>
#include <math.h>

//mudar para nome mais especifico
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

int faz_soma(pilha *p){
	int num = getNum(p) + getNum(p);
	insertNum(p, num);
	//printf("\n\n soma = %d \n", num);
	return num;
}

int faz_mult(pilha *p){
	int num1 = getNum(p);
	if(isEmpty(p)){
		insertNum(p, num1);
		return num1;
	}
	int num2 = getNum(p);
    int num = num1 * num2;
    insertNum(p, num);
	//printf("\n\n mult = %d \n", num);
	return num;
}

int faz_div(pilha *p){
	int num1 = getNum(p), num;
	if(isEmpty(p)){
		insertNum(p, num1);
		return num1;
	}
	int num2 = getNum(p);
    num = num2 / num1;
    insertNum(p, num);
	//printf("\n\n div = %d \n", num);
	return num;
}

int faz_sub(pilha *p){
	int num1 = getNum(p), num;
	if(isEmpty(p)){
		insertNum(p, num1);
		return num1;
	}
	int num2 = getNum(p);
	//printf("\n\n num2 = %d \n", num2);
    num = num2 - num1;
    insertNum(p, num);
	//printf("\n\n sub = %d \n", num);
	return num;
}

int clear_calc(pilha *p){
	if(!isEmpty(p)){
		while(p->topo->anterior != NULL)
			getNum(p);
		getNum(p);
		return 0;
	}else{
		//printf("Erro ao evaziar a pilha!\nA pilha ja esta vazia\n\n");
		return 1;
	}
}





