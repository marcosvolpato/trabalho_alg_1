/*
 * date: 20/09/2015
 * description: Exercicio de ALG1.
 *				Consiste em uma pilha de inteiros
 *				Deve-se criar uma pilha e usar a fun��o iniciar().
 *				Para empilhar deve-se usar o a fun��o insertNum().
 *				E para desempilhar deve-se usar a fun��o getNum().
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
#ifndef _PILHANUM_H_
#define _PILHANUM_H_

/*
 * Define a estrutura n� que contem um inteiro e um endere�o de n�
 * para o encadeamento em pilha
 */
typedef struct No{
	int num;
	struct No *anterior;
}no;

/*
 * Define a estrutura pilha que contem um n� topo e 
 * um int para guardar o tamanho da pilha
 */
typedef struct Pilha{
	no *topo;
	int tamanho;
}pilha;

/*
 * Aloca espa�o na memoria para uma pilha e retorna seu endere�o
 */
void *inicia();

/*
 * Recebe um ponteiro para pilha e retorna 1 se estiver vazia
 */
int isEmpty(pilha *p);

/*
 * Recebe um ponteiro para pilha e imprime na tela todos os ints
 * contidos nos n�s dessa pilha come�ando do topo
 */
void consulta(pilha *p);

/*
 * Faz a mesma coisa que a fun��o consulta(), mas imprime
 * os nummeros pela ordem inversa
 */
void consulta_inversa(pilha *p);

/*
 * Recebe um ponteiro para pilha em um numero inteiro
 * cria umm novo n� e insere na pilha tornando-o o 
 * novo topo.
 */
void insertNum(pilha *p, int num);

/*
 * Recebe um ponteiro para pilha e retira o n� que est�
 * no topo da pilha, libera o espa�o na memoria ocupado 
 * por esse no e retorna o int que estava contido nesse
 * n�
 */
int getNum(pilha *p);

#endif
