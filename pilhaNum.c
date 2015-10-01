#include <stdio.h>
#include <stdlib.h>
#include "pilhaNum.h"

void *inicia(){
	pilha *p = (pilha *)malloc(sizeof(pilha));
	if(p != NULL){
		p->topo = NULL;
		p->tamanho = 0;
	}
	return p;
}

int isEmpty(pilha *p){
	return (p->topo == NULL);
}

no *aloca(int num){
	no *novo=(no *) malloc(sizeof(no));
	if(!novo){
		printf("Erro! Sem memoria!\n");
		exit(1);
	}else{
		novo->num = num;
		return novo;
	}
}

void deletaPilha(pilha **p){
	if(!isEmpty(*p)){
		no *aux = (*p)->topo;
		
		while(aux != NULL){
			no *aux2 =aux;
			aux = aux->anterior;
			free(aux2);
		}
	}
	free(*p);
	*p = NULL;
}

void push(pilha *p, int num){
	if(isEmpty(p)){
		p->topo = aloca(num);
		p->topo->anterior = NULL;
	}
	else{
		no *aux = p->topo;
		p->topo = aloca(num);
		p->topo->anterior = aux;
	}
	p->tamanho++;
}

int pop(pilha *p){
	if(isEmpty(p)){
		return NULL;
	}else{
		int num = p->topo->num;
		no *aux = p->topo;
		
		if(p->topo->anterior != NULL){
			p->topo = p->topo->anterior;
			free(aux);
			return num;
		}else{
			p->topo = NULL;
			free(aux);
			return num;
		}
		p->tamanho--;
	}
}

void consulta(pilha *p){
	//printf("\n\nResultado da pesquisa:\n");
	no *aux = p->topo;
	while(aux != NULL){
		printf("%d ", aux->num);
		if(aux->anterior != NULL)
			aux = aux->anterior;
		else
			break;
	}
}
void consulta_inversa(pilha *p){
	pilha *p2 = inicia();
	no *aux = p->topo;
	while(aux != NULL){
		push(p2, aux->num);
		if(aux->anterior != NULL)
			aux = aux->anterior;
		else
			break;
	}
	consulta(p2);
	deletaPilha(&p2);
}

int getNum(pilha *p){
	return pop(p);
}

void insertNum(pilha *p, int num){
	push(p, num);
}

int tamanho(pilha *p){
	return p->tamanho;
}

int *topo(pilha *p){
	if(!isEmpty(p))
		return &(p->topo->num);
	return NULL;
}
