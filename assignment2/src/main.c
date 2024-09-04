#include "mystring.h"
#include<string.h>

int main(void)
{
		char stringA[100] = "I want cake";


		printf("The string's length is %ld.\n", ms_length(stringA) );
		printf("The string's length is %ld.\n\n", strlen(stringA) );


		printf("Search: %s\n", ms_search(stringA, "want") );
		printf("Search: %s\n\n", strstr(stringA, "want") );

		printf("Copy: %s\n", ms_copy(stringA, "I want Pie.") );
		printf("Copy: %s\n\n", strcpy(stringA, "I want Pie.") );

		printf("Copyn: %s\n", ms_ncopy(stringA, "I want Pie.", 8) );
	/*	printf("Copyn: %s\n\n", strncpy(stringA, "I want Pie.", 1) );*/

		printf ("Concat: %s\n", ms_concat(stringA, " krepa ") );
		printf ("Concat: %s\n\n", strcat(stringA, " krepa ") );

		printf ("Concatn:%s\n", ms_nconcat(stringA, " lacta ", 3) );
		printf ("Concatn:%s\n\n", strncat(stringA, " lacta ", 3) );

		printf("Compare: %d\n", ms_compare("yioupi", "yioupa"));
		printf("Compare: %d\n\n", strcmp("yioupi", "yioupa"));

		printf ("Comparen: %d\n", ms_ncompare("yioupiopp", "yioupi",10) );
		printf ("Comparen: %d\n", strncmp("yioupiopp", "yioupi",10) );
	
	return 0;
}
