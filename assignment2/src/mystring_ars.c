/*
Nasia Boubouraki
assignment2
mystring_ars.c
*/

#include "mystring.h"

/* Return the length of string `pcStr`.

   It is a checked runtime error for `pcStr` to be NULL. */
size_t ms_length(const char pcStr[]) {

	size_t uiLength = 0U;

	assert(pcStr); /* Works because NULL and FALSE are identical. */

	while (pcStr[uiLength]) /* Works because end-of-string and FALSE are identical. */

		uiLength++;

	return uiLength;

}

/*Copies *source to destination

  Returns a pointer to destination
*/
char* ms_copy(char destination[], const char source[]) {
	char* temp  = destination;
	size_t j = 0U;
	size_t i = 0U;

	assert(destination);
	assert(source);
	while ((*(destination + i++) = *(source + j++)));
	return temp;
}

/*Copies up to num chars from *source to destination

  Returns the final copy of the copied string
*/
char* ms_ncopy(char destination[], const char source[], size_t num) {
	char* temp = destination;
	size_t i= 0U;
	size_t j = 0U;
	assert(destination);
	assert(source);
	if (num > 0) {
		while (num-- && (*(destination + i++) = *(source + j++)));
	}
	return temp;
}

/*Appends *source to the end of *destination

  Returns a pointer to destination
*/
char* ms_concat(char destination[], const char source[]) {
	size_t j = 0U;
	size_t i = ms_length(destination);

	assert(destination);
	assert(source);
	while ((*(destination + i++) = *(source + j++)) != '\0');
	return destination;
}

/*Appends *source to the end of *destination up to num chars long

  Returns a pointer to destination
*/
char* ms_nconcat(char destination[], const char source[], size_t num) {
	size_t j = 0U;	
	size_t i = ms_length(destination);
	assert(destination);
	assert(source);
	if (num > 0) {
		while (num-- && (*(destination + i++) = *(source + j++)));
	}
	return destination;
}

/*Compares the *string1 to *string2

  Returns value < 0 if string1 is less than string2.

  Returns value > 0 if string2 is less than string1.

  Returns 0 string1 is equal to string2.
*/
int ms_compare(const char string1[], const char string2[]) {
	int i ;
	i = 0;
	assert(string1);
	assert(string2);
	while ((string1[i] != '\0') || (string2[i] != '\0'))
	{
		if (string1[i] > string2[i])
			return 1;
		if (string1[i] < string2[i])
			return -1;
		i++;
	}

	return 0;
}

/*Compares at most the firstnumbytes of string1 and string2

  Returns value < 0 if string1 is less than string2.

  Returns value > 0 if string2 is less than string1.

  Returns 0 string1 is equal to string2.
*/
int ms_ncompare(const char string1[], const char string2[], size_t n) {
	int i ;
	i = 0;
	assert(string1);
	assert(string2);

	while ((string1[i] != '\0') && (string1[i]==string2[i]) && n)
	{
		i++;
		--n;
	}
	if (n == 0)
	{
		return 0;
	}
	else
	{
		if (string1[i] > string2[i])
			return 1;	
	}
	return -1;

}

/*Finds the first occurrence of the substring string2 in the string1

  Returns a pointer to the first occurrence in string1 of string2,  or a null pointer
*/
char* ms_search(const char string1[], const char string2[]) {
	size_t i= 0;
	size_t j=0;
	size_t pos=0;
	assert(string1);
	assert(string2);

	while (i<ms_length(string1))
	{	
		if ((string1[i] == string2[0])) 
		{	
			pos=i;
			while(j<ms_length(string2)){
				if(string1[pos]!=string2[j]) break;
				++j;
				++pos;
			}
			
			if(j==ms_length(string2)) {
				
				return (char*)& string1[i];
			}

		}
		++i;
	}

	return NULL;
}
