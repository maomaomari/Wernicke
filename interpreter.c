#include "interpreter.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Fita *criaFita(){
	Fita *tmpPtr = (Fita*)malloc(sizeof(Fita));
	return tmpPtr;
}

Fita *parser(Fita* ptrFita,  char *instr){
	Stack *ptrStack = NULL;
	for(; *instr != '\0'; instr++){
		if(ptrStack != NULL && ptrFita->val == 0){
			while(*instr != ']'){
				instr = instr+1;
			}
			instr = instr +1;
			ptrStack = removeStack(ptrStack);
		}
	
		switch(*instr){
			case '>':
				if(!ptrFita->prox){
					ptrFita->prox = criaFita();
					*(ptrFita->prox) = (Fita){.val = 0, .prox = NULL, .ante = ptrFita };
				}
				ptrFita = ptrFita->prox;
				break;
			case '<':
				if(!ptrFita->ante){
					ptrFita->ante = criaFita();
					*(ptrFita->ante) = (Fita){.val = 0, .prox = ptrFita, .ante = NULL };
				}
				ptrFita = ptrFita->ante;
				break;
			case '+':
				ptrFita->val++;
				break;
			case '-':
				ptrFita->val--;
				break;
			case '.':
				printf("%02X\n", ptrFita->val);
				break;
			case ',':
				int tmp;
				scanf("%d", &tmp);
				if(tmp > 255 || tmp < 0)
					break;
				ptrFita->val = tmp;
				break;
			case '[':
				ptrStack = addStack(ptrStack, instr);
				break;
			case ']':
				instr = ptrStack->pos;
				break;
			default:
				break;
		}
	}
	return ptrFita;
}
