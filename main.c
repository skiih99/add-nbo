#include <stdio.h>
#include <stdint.h>
#include "add-nbo.h"

int main(int argc, char* argv[]){
	FILE *fp1, *fp2;
	uint32_t a, b;

	if(argc != 3){
		printf("Syntax Error.\n");
		return -1;
	}

	fp1 = fopen(argv[1], "rb");
	fp2 = fopen(argv[2], "rb");

	if(fp1 == NULL || fp2 == NULL){
		printf("File Open Error.\n");
		return -1;
	}
	
	fread(&a, 1, 4, fp1);
	fread(&b, 1, 4, fp2);

	add_nbo(a, b);

	fclose(fp1);
	fclose(fp2);

	return 0;
}
