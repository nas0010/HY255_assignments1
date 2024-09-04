#include <stdio.h>
#include<stdlib.h>

int main(){
	char c = '*';
	int i=0;
	FILE * fptr= fopen("data3","w");
	if(fptr==NULL) exit(EXIT_FAILURE);
	for(i=0;i<18;i++){
		fputc(c,fptr);
	}

	fputc('\0',fptr);
	 /*try to write stuff wherever i dont have permission after buff */
	for(i=0;i<33;i++){
		fputc('*',fptr);
	}

	
	fclose(fptr);	
	
	return 0;
}
