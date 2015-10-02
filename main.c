/*
 * Title: 		Polish Calculator 
 *
 * Date: 		02/10/2015
 *
 * Description: Trabalho de ALG1 da USP ICMC
 *				Consiste em uma calculadora que recebe como entrada numeros inteiros positivos
 *				e utiliza nota��o polonesa para fazer o calculo.
 *				S�o 6 opera��es permitidas: soma, subtra��o, divis�o ,multiplica��o, fatorial 
 *				e potencia indicados pelos sinais +, -, /, *, ! e ^ respectivamente.
 *				O programa faz uso de uma pilha de inteiros para armazenar os numeros informados
 *				pelo usuario que informa uma express�o completa do calculo desejado.
 *				
 * Usage:		Exemplo de express�o a inserir: E90E20E15E13-*E5+/
 *				O resultado esperado � 2.
 *				A nota��o polonesa recebe os numeros primeiro e o operador depois, quando um 
 *				operador � inserido ele desempilha os dois ultimos numeros e os calcula
 * 				empilhado novamente o resultado. O caracter E � usado para indicar que um 
 *				numero sera inserido.
 *
 * Repository: 	https://github.com/marcosvolpato/trabalho_alg_1
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
#include <locale.h>
#include "loop.h"

int main(int argc, char *argv[]) {
	
	//inicia o loop principal em loop.c
	loop();
	system("pause");
	return 0;
}
