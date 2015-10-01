#ifndef _PILHANUM_H_
#define _PILHANUM_H_

typedef struct No{
	int num;
	struct No *anterior;
}no;

typedef struct Pilha{
	no *topo;
	int tamanho;
}pilha;

void *inicia();
int isEmpty(pilha *p);
void consulta(pilha *p);
void consulta_inversa(pilha *p);
void insertNum(pilha *p, int num);
int getNum(pilha *p);

#endif
