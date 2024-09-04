/*
Nasia Boubouraki
assignment2
mystring_ptrs.c
*/

#include "mystring.h"

/* Return the length of string `pcStr`.

   It is a checked runtime error for `pcStr` to be NULL. */

size_t ms_length(const char* pcStr) {

	const char* pcStrEnd ;
	pcStrEnd = pcStr;

	assert(pcStr); /* Works because NULL and FALSE are identical. */

	while (*pcStrEnd) /* Works because end-of-string and FALSE are identical. */

		pcStrEnd++;

	return pcStrEnd - pcStr;

}

/*Copies *source to destination

  Returns a pointer to destination
*/
char* ms_copy(char* destination, const char* source) {
    char* temp = destination;
    assert(destination);
    assert(source);
	while ((*destination++ = *source++) != '\0');
    return temp;
}

/*Copies up to num chars from *source to destination

  Returns the final copy of the copied string
*/
char* ms_ncopy(char* destination, const char* source, size_t num) {
	char* temp= destination;
	assert(destination);
	assert(source);
	if (num > 0) {
		while (num-- && (*destination++ = *source++));
	}
	return temp;
}

/*Appends *source to the end of *destination

  Returns a pointer to destination
*/
char* ms_concat(char* destination, const char* source) {
	assert(destination);
	assert(source);
	ms_copy(destination + ms_length(destination), source);
	return destination;
}

/*Appends *source to the end of *destination up to num chars long

  Returns a pointer to destination
*/
char* ms_nconcat(char* destination, const char* source, size_t num) {
	assert(destination);
	assert(source);
	ms_ncopy(destination + ms_length(destination), source,num);
	return destination;
}

/*Compares the *string1 to *string2

  Returns value < 0 if string1 is less than string2.

  Returns value > 0 if string2 is less than string1.

  Returns 0 string1 is equal to string2.
*/
int ms_compare(const char* string1, const char* string2) {
	assert(string1);
	assert(string2);
	while (*string1 ){
		if(*string1 != *string2){
			break;
		}
	
		string1++;
		string2++;
	}

	return *(const unsigned char*)string1 - *(const unsigned char*)string2;
}

/*Compares at most the firstnumbytes of string1 and string2

  Returns value < 0 if string1 is less than string2.

  Returns value > 0 if string2 is less than string1.

  Returns 0 string1 is equal to string2.
*/
int ms_ncompare(const char* string1, const char* string2, size_t n) {
	assert(string1);
	assert(string2);	
	while (n && *string1 && (*string1 == *string2))
	{
		string1++;
		string2++;
		--n;
	}
	if (n == 0)
	{
		return 0;
	}else
	{
		return *(const unsigned char*)string1 - *(const unsigned char*)string2;
	}
}

/*Finds the first occurrence of the substring string2 in the string1

  Returns a pointer to the first occurrence in super of string2,  or a null pointer
*/
char* ms_search(const char* string1, const char* string2) {
	const char *temp;
	const char *pos;
	assert(string1);
	assert(string2);
	
	while (*string1 != '\0')
	{
		if ((*string1 == *string2)) {
			pos=string1;
			temp=string2;
			while(*temp!='\0'){
				if(*pos!=*temp) break;
				++pos;
				++temp;

			}
			if(*temp=='\0')
			return (char*)string1;
		}
		string1++;
	}

	return NULL;
}
