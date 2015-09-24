#include <stdio.h>
#include <stdlib.h>
#include "pilhaint.h"
/*
 * title: Pilha 
 * date: 20/09/2015
 * description: Exercicio de ALG1.
 *				Consiste em uma pilha de inteiros
 *				Deve-se criar uma pilha e usar a função iniciar().
 *				Para empilhar deve-se usar o a função insertNum().
 *				E para desempilhar deve-se usar a função getNum().
 *				Exemplo de uso na função main().
 * author: Allan Ribeiro da Costa   NºUSP
 *         Marcos Vinicius Volpato  NºUSP 9364872
 * 
 *
 */


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
		no *prox, *atual;
		atual = p->topo;
		
		while(atual != NULL){
		prox = atual->prox;
		free(atual);
		atual = prox;
		}
	}
}


void push(pilha *p, int num){
	no *novo = aloca(num);
	novo->prox = NULL;

	if(isEmpty(p))
		p->topo = novo;
	else{
		no *aux = p->topo;

		while(aux->prox != NULL)
			aux = aux->prox;
	
		aux->prox = novo;
	}
	p->tamanho++;
}

no *pop(pilha *p){
	if(p->topo == NULL){
		printf("pilha vazia\n\n\n");
		return NULL;
	}else{
		if(p->topo->prox == NULL){
			no *aux = p->topo;
			return aux;
		}else{
		
			no *ultimo = p->topo, *penultimo = p->topo->prox;
			no *aux = p->topo->prox, *aux2 = p->topo;
			p->topo = aux;
			return aux2;
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

/*int main(){
	
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
	 
	return 0;
}
*/

