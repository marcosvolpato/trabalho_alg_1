#include "pilhanum.h"
#include <stdio.h>
#include <math.h>
#define DEBUG 1

//mudar para nome mais especifico
int faz_calculo(pilha *p, int count){

	int num = 0;
	int pot = 0;
	while(count > 0){
		num += (getNum(p) * pow(10, pot));
		if(DEBUG)
			printf("\n%d\n", num);
		count--;
		pot++;
	}
	insertNum(p, num);
	return count;
}

int faz_soma(pilha *p){
	int num = getNum(p) + getNum(p);
	insertNum(p, num);
	printf("\n\n soma = %d \n", num);
	return num;
}

int faz_mult(pilha *p){
    int num = getNum(p) * getNum(p);
    insertNum(p, num);
	printf("\n\n mult = %d \n", num);
	return num;
}

int faz_div(pilha *p){
    int num = getNum(p) / getNum(p);//ver quem divide quem
    insertNum(p, num);
	printf("\n\n div = %d \n", num);
	return num;
}

int faz_sub(pilha *p){
    int num = getNum(p) - getNum(p);//ver quem subtrai quem
    insertNum(p, num);
	printf("\n\n sub = %d \n", num);
	return num;
}

int clear_calc(pilha *p){
	if(!isEmpty(p)){
		while(p->topo->anterior != NULL)
			getNum(p);
		getNum(p);
		return 0;
	}else{
		printf("Erro ao evaziar a pilha!\nA pilha ja esta vazia\n\n");
		return 1;
	}
}





