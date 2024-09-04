/*
Nasia Boubouraki
assignment2
mystring.h
*/
#include <stddef.h>
#include <assert.h>
#include <stdio.h>

/* Return the length of string pcStr.

   It is a checked runtime error for `pcStr` to be NULL. 
 */
size_t ms_length(const char pcStr[]);

/*Copies *source to destination

  Returns a pointer to destination
*/
char* ms_copy(char* destination, const char* source);

/*Copies up to num chars from *source to destination

  Returns the final copy of the copied string
*/
char* ms_ncopy(char* destination, const char* source, size_t num);

/*Appends *source to the end of *destination
  
  Returns a pointer to destination
*/
char* ms_concat(char* destination, const char* source);

/*Appends *source to the end of *destination up to num chars long

  Returns a pointer to destination
*/
char* ms_nconcat(char* destination, const char* source, size_t num);

/*Compares the *string1 to *string2

  Returns value < 0 if string1 is less than string2.

  Returns value > 0 if string2 is less than string1.

  Returns 0 string1 is equal to string2.
*/
int ms_compare(const char* string1, const char* string2);

/*Compares at most the firstnumbytes of string1 and string2
 
  Returns value < 0 if string1 is less than string2.

  Returns value > 0 if string2 is less than string1.

  Returns 0 string1 is equal to string2. 
*/
int ms_ncompare(const char* string1, const char* string2, size_t n);

/*Finds the first occurrence of the substring sub in the string super
  
  Returns a pointer to the first occurrence in super of sub,  or a null pointer 
*/
char* ms_search(const char* super, const char* sub);

