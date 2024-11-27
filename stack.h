#ifndef _STACK
#define _STACK

typedef struct stack{
	char *pos;
	struct stack *next;
} Stack;

Stack *initStack(Stack*, char*);
Stack *addStack(Stack*, char*);
Stack *removeStack(Stack*);

#endif
