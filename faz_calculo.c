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








