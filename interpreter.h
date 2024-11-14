#ifndef _INTERPRETER
#define _INTERPRETER

typedef struct fita{

	int val;
	struct fita *prox;
	struct fita *ante;
	
}Fita;

Fita *criaFita();

void parse(void);



#endif
