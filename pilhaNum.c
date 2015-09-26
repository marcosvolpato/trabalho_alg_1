#include <stdio.h>
#include <stdlib.h>
#include "pilhaNum.h"

void inicia(pilha *p){
	p->topo = NULL;
	p->tamanho = 0;
}

int isEmpty(pilha *p){
	if(p->topo == NULL)
		return 1;
	else
		return 0;
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

void libera(pilha *p){
	if(!isEmpty(p)){
		no *ant, *atual;
		atual = p->topo;
		
		while(atual != NULL){
		ant = atual->anterior;
		free(atual);
		atual = ant;
		}
	}
}

void push(pilha *p, int num){
	no *novo = aloca(num);
	if(!isEmpty(p)){
		novo->anterior = p->topo;
		
	}else{
		novo->anterior = NULL;
	}
	p->topo = novo;
	p->tamanho++;
}

no *pop(pilha *p){
	if(p->topo == NULL){
		printf("pilha vazia\n\n\n");
		return NULL;
	}else{
		if(p->topo->anterior != NULL){
			no *aux = p->topo;
			p->topo = p->topo->anterior;
			return aux;
		}else{
			return p->topo;
		}
	}
}

int getNum(pilha *p){
	no *aux = pop(p);
	int num = aux->num;
	free(aux);
	return num;
}

void insertNum(pilha *p, int num){
	push(p, num);
}
