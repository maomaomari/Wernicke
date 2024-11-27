#include "stack.h"
#include <stdlib.h>


Stack *initStack(Stack *ptrStack, char *pos){
	ptrStack = (Stack*)malloc(sizeof(Stack));
	*ptrStack = (Stack){ .pos = pos};
	return ptrStack;
}

Stack *addStack(Stack *ptrStack, char *pos){

	if(!ptrStack)
		ptrStack = initStack(ptrStack, pos);
	else {
		Stack *tmp = ptrStack;
		ptrStack = &(Stack){.next = tmp, .pos = pos };
	}

	return ptrStack;
}
Stack *removeStack(Stack *ptrStack){
	if(ptrStack->next == NULL){
		free(ptrStack);
		return NULL;
	}
	Stack *tmp = ptrStack;
	ptrStack = ptrStack->next;
	free(tmp);
	
	return ptrStack;
}
