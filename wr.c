/*
  > move uma cédula na fita
  < move uma cédula na fita
  + incrementa
  - decrementa
  , entrada
  . saida
  [ inicio de loop
  ] fim de loop

  maxsize é unsigned char
  todo caractere q n for um operador é um comentário

  loops retornam quando a cédula presente conter 0
  
*/

#include <stdio.h>
#include "interpreter.h"

Fita fitaMain = {};


int main(int argc, char** argv){
	FILE *src;
	if(argv[1]){
		src = fopen(argv[0], "r");
		printf("%s\n", argv[1]);
	} else {
		;
	}
	return 0;
}
