/* 
 *
 * Date: 		02/10/2015
 *
 * Description: Função que contem as operações necessarias para tratar os chars 
 *				do programa Polish Calculator
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

#ifndef _LOOP_H_
#define _LOOP_H_

/*
 * desempilha um numero e soma com outro tbm 
 * desempilhado, este vezes 10 e empilha o resultado
 */
int faz_calculo(pilha *p);

/*
 * desempilha dois numeros, faz a soma entre eles 
 * e empilha o resultado
 */
int faz_soma(pilha *p);

/*
 * desempilha dois numeros, faz a multiplicação entre eles 
 * e empilha o resultado
 */
int faz_mult(pilha *p);

/*
 * desempilha dois numeros, divide o segundo desepilhado pelo primeiro 
 * e empilha o resultado
 */
int faz_div(pilha *p);

/*
 * desempilha dois numeros, subtrai o primeiro desepilhado do segundo 
 * e empilha o resultado
 */
int faz_sub(pilha *p);

/*
 * recebe um ponteiro de pilha, limpa essa pilha e retorna 0
 * se tiver sucesso e 1 se a pilha ja estiver vazia
 */
int clear_calc(pilha *p);

#endif

