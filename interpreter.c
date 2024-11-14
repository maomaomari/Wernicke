#include "interpreter.h"
#include <stdio.h>
#include <stdlib.h>

Fita *criaFita(){
	Fita tmp = { };
	Fita *tmpPtr = (Fita*)malloc(sizeof(Fita));
	tmpPtr = &tmp;
	return tmpPtr;
}

void parser(Fita* ptrFita, char *instr){
	switch(*instr){
		case '>':
			if(!ptrFita->prox)
				ptrFita->prox = criaFita();
			ptrFita = ptrFita->prox;
		case '<':
			if(!ptrFita->ante)
				ptrFita->ante = criaFita();
			ptrFita = ptrFita->ante;
		case '+':
			ptrFita->val++;
		case '-':
			ptrFita->val--;
		case '.':
			printf("%02x", ptrFita->val);
		case ',':
			int tmp;
			scanf("%d", &tmp);
			if(tmp > 255 || tmp < 0)
				break;
			ptrFita->val = tmp;
		case '[':

		case ']':

		default:
			break;
	}
}
