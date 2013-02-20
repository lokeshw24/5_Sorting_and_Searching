/*WHAT PROG DOES :
 * Implementation of *modified* "Insertion Sort". Here we remember the previous insertion & use 
 * this info to take quicker decision while next insertion.
 *
 */

#include<stdio.h>
#include"../array_functions.h"

/*********************************************************************/
void insertion_sort( int *arr, int arr_size ){
	int i;
	int *previous_insertion, *last, *first ;
	previous_insertion=first;
	
	for( i=1 ; i<=arr_size ; i++ ){
		printf("i: %d \n" , i );

		last=arr+i;
		if( *last>=(*previous_insertion) )
			first=previous_insertion;
		else
			first=arr;


		while( first!=last ){
			if( *first>*last ){

				int t=*last;
				int *temp=last-1;
				while(temp!=first){
					*(temp+1)=*temp;
					--temp;
				}
				*(temp+1)=*temp;
				*first=t;
				previous_insertion=first;
			}
			first++;
		}

	}//end for
}
/*********************************************************************/

int main(){
	int arr[]={-8, 22, 55 ,3, 323,-2,55,-23};
	int arr_size=7;

	insertion_sort( arr, arr_size );
	print_array( arr, arr_size );

return 0;

}
