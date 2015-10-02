/*
 * date: 20/09/2015
 * description: Exercicio de ALG1.
 *				Consiste em uma pilha de inteiros
 *				Deve-se criar uma pilha e usar a função iniciar().
 *				Para empilhar deve-se usar o a função insertNum().
 *				E para desempilhar deve-se usar a função getNum().
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
#include "pilhaNum.h"

//aloca espaço para uma pilha e retorna seu ponteiro
void *inicia(){
	pilha *p = (pilha *)malloc(sizeof(pilha));
	if(p != NULL){
		p->topo = NULL;
		p->tamanho = 0;
	}
	return p;
}

//recebe um ponteiro de pilha e retorna 1 se esta estiver vazia
int isEmpty(pilha *p){
	return (p->topo == NULL);
}

//aloca espaço para um nó e insere no nó o int recebido como parametro
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

//deleta completamente uma pilha liberando o espaço antes alocado em memória
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

//insere um nó no topo da pilha
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

//retira o no do topo e retorna o int desse nó
int pop(pilha *p){
	if(isEmpty(p)){
		printf("Erro fatal de pilha! O programa será encerrado.");
		system("pause");
		exit(0);
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

//imprime na tela todos os int dos nós empilhados atualmente
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

//imprime na tela todos os int dos nós empilhados atualmente, mas começando da base, nao do topo
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

//handler para o pop()
int getNum(pilha *p){
	return pop(p);
}

//handler para o push()
void insertNum(pilha *p, int num){
	push(p, num);
}

//retorna o tamanho de uma pilha
int tamanho(pilha *p){
	return p->tamanho;
}

//retorna o nó que está no topo da pilha
int *topo(pilha *p){
	if(!isEmpty(p))
		return &(p->topo->num);
	return NULL;
}
