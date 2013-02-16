/*WHAT PROG DOES :
 * Implementation of "Insertion Sort"
 *
 */

#include<stdio.h>
#include"../array_functions.h"

/*********************************************************************/
void insertion_sort( int *arr, int arr_size ){
	int i;
	
	for( i=1 ; i<=arr_size ; i++ ){
		int *last=arr+i;
		int *first=arr;

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
			}
			first++;
		}

	}//end for
}
/*********************************************************************/

int main(){
	int arr[]={-8, -22, -55};
	int arr_size=2;

	insertion_sort( arr, arr_size );
	print_array( arr, arr_size );

return 0;

}
