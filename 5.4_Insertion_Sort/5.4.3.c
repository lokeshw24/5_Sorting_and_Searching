/*WHAT PROG DOES :
 * Implementation of "modified" "Insertion Sort". Here we insert 2 elements in every iteration.
 *
 */

#include<stdio.h>
#include"../array_functions.h"

/*********************************************************************/
void insertion_sort( int *arr, int arr_size ){
	int i, smaller, larger;
	int *last, *first, *position_smaller, *position_larger,*temp;
	
	for( i=1 ; i<arr_size ; i+=2 ){
		last=arr+i;
		first=arr;
		position_smaller=NULL;
		position_larger=NULL;

		if( *last<*(last+1) ){
			smaller=*last;
			larger=*(last+1);
		}
		else{
			larger=*last;
			smaller=*(last+1);
		}

		print_array( arr, arr_size );
		printf("Smaller, Larger : %d %d \n", smaller , larger );

		/*find the positions where the smaller & larger of the 2 elements should be inserted */

		while( first!=last ){
			if( *first>smaller){
				position_smaller=first;
				break ;
			}
			first++;
		}
		if( position_smaller==NULL ){
			if ( *last>(*(last+1)) ) {
				/* so swap elements (last) & (last+1) */
				*last=smaller;
				*(last+1)=larger;
			}
			continue;
		}
		
		while( first!=last ){
			if( *first>larger){
				position_larger=first;
				break ;
			}
			first++;
		}
		
		if( position_larger==NULL ){
			if( *last>(*(last+1)) ){
				*(last+1)=larger;
				*last=smaller;
			}
			temp=last;
		}

		if( position_smaller && position_larger )printf(" position_smaller , position_larger ,last: %d %d %d \n", *position_smaller , *position_larger, *last );

		/*Move all elements from the position_larger by 2 places ahead */
		if( position_larger ){
			temp=last;
			while( temp>position_larger){
				printf("temp : %d \n", *temp );
				*(temp+1)=*(temp-1);
				temp--;
			}
			*(position_larger+1)=larger;
		}

		/*Now from position_larger till position_smaller, move all elements by 1 ahead */
		while( temp>position_smaller){
			*temp=*(temp-1);
			temp--;
		}
		*temp=smaller;

	}//end for
	

	if( i!=arr_size ) return ;

	printf("$$ \n");
	last=arr+i;
	first=arr;

	while( *first<*last )first++;
	
	if( first < last ) {

			int t=*last;
			int *temp=last-1;
			while(temp!=first){
				*(temp+1)=*temp;
				--temp;
			}
			*(temp+1)=*temp;
			*temp=t;
		}
	
}
/*********************************************************************/

int main(){
	int arr[]={-8, -22 };
	int arr_size=1;

	insertion_sort( arr, arr_size );
	print_array( arr, arr_size );

return 0;

}
