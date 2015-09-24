#include <stdio.h>
#include <stdlib.h>
#include "pilhaint.h"

int main(int argc, char *argv[]) {
	pilha p;
	inicia(&p);
	 
	insertNum(&p, 7);
	insertNum(&p, 14); 
	insertNum(&p, 21);
	insertNum(&p, 28); 
	 
	printf("%d \n\n", getNum(&p));
	printf("%d \n\n", getNum(&p));
	printf("%d \n\n", getNum(&p));
	printf("%d \n\n", getNum(&p));
	system("pause");
	return 0;
}
