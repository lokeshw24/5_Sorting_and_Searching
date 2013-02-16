/*WHAT PROG DOES :
 * Was trying to test the fact given in point no.5 at page 197 of Dromey.
 * 
 * It could happen that my formula is wrong, so need to discuss this with someone.
 *
 */

#include<stdio.h>
#include<limits.h>

int main(){
	float n, first, sec ;
	printf("%d " , INT_MAX );

	return 0 ;

	for( n=0 ; n<INT_MAX ; n++ ){
		first=3*((0.75*n*n) + (n/2) );
		sec= n*(n-1) ;
		if( first < sec )
			printf("$$ %f \n", n );

	}

return 0;

}

