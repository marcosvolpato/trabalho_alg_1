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
#ifndef _PILHANUM_H_
#define _PILHANUM_H_

/*
 * Define a estrutura nó que contem um inteiro e um endereço de nó
 * para o encadeamento em pilha
 */
typedef struct No{
	int num;
	struct No *anterior;
}no;

/*
 * Define a estrutura pilha que contem um nó topo e 
 * um int para guardar o tamanho da pilha
 */
typedef struct Pilha{
	no *topo;
	int tamanho;
}pilha;

/*
 * Aloca espaço na memoria para uma pilha e retorna seu endereço
 */
void *inicia();

/*
 * Recebe um ponteiro para pilha e retorna 1 se estiver vazia
 */
int isEmpty(pilha *p);

/*
 * Recebe um ponteiro para pilha e imprime na tela todos os ints
 * contidos nos nós dessa pilha começando do topo
 */
void consulta(pilha *p);

/*
 * Faz a mesma coisa que a função consulta(), mas imprime
 * os nummeros pela ordem inversa
 */
void consulta_inversa(pilha *p);

/*
 * Recebe um ponteiro para pilha em um numero inteiro
 * cria umm novo nó e insere na pilha tornando-o o 
 * novo topo.
 */
void insertNum(pilha *p, int num);

/*
 * Recebe um ponteiro para pilha e retira o nó que está
 * no topo da pilha, libera o espaço na memoria ocupado 
 * por esse no e retorna o int que estava contido nesse
 * nó
 */
int getNum(pilha *p);

#endif
