#include <stdio.h>
#include <stdlib.h>
#include "interpreter.h"

int main(int argc, char** argv){

	FILE *src = fopen(argv[1], "rb");
	long leng;
	static char *buf;
	
	if(src != NULL){
		fseek(src, 0, SEEK_END);
		leng = ftell(src);
		fseek(src, 0, SEEK_SET);
		buf = (char*) malloc(leng +1);
		if(buf)
			fread(buf, 1, leng, src);
		fclose(src);
		buf[leng] = '\0';
	}

	Fita *ft = criaFita();
	*ft = (Fita){ 0 };
	ft = parser(ft, buf);
	
	return ft->val;
}
