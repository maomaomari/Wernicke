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
#include <stdlib.h>
#include "interpreter.h"

int main(int argc, char** argv){

	FILE *src = fopen(argv[1], "rb");
	long leng;
	char *buf = {};

	if(src){
		fseek(src, 0, SEEK_END);
		leng = ftell(src);
		fseek(src, 0, SEEK_SET);
		buf = (char*) malloc(leng +1);
		if(buf)
			fread(buf, 1, leng, src);
		fclose(src);
		buf[leng] = '\0';
	}

	printf("%s\n\n\n", buf);
	Fita * ft = criaFita();
	*ft = (Fita){ 0 };
	//	char str[30] = "+.>++.>+++.>,.<.<.<.";
	for(int i = 0; buf[i] != '\0'; i++){
		ft = parser(ft, (buf+i));
	}
	return 0;
}
