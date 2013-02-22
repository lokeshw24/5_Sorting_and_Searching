#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct abc{
	char *original_word;
	char *meaning;
	int hash_key;

	struct abc *next ;
	struct abc *linear_chain;
}node;
/*******************************************************/

typedef node * dict ;


