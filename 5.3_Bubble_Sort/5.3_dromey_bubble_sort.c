/*WHAT PROG DOES : 
 * Implements "bubble sort", as given in Dromey. Here during an iteration if no swapping is made 
 * then the array is sorted & thus we stop immediately.
 *
 */

#include<stdio.h>
#include"../array_functions.h"

#define TRUE 0
#define FALSE 1

/*********************************************************************/
void bubble_sort( int *arr , int arr_size ){
	int *first, *second, i ,j ;
	int sorted=FALSE;

	for( i=0 ; i<arr_size && sorted==FALSE ; i++ ){
		first=arr;
		second=first+1;
		sorted=TRUE;

		for( j=i; j<arr_size ; j++ ){
			if( *first>*second ){
				sorted=FALSE;
				int t=*first;
				*first=*second;
				*second=t;
			}
			first++;
			second++;
		}

	}//end for


}
/*********************************************************************/

int main(){
	int arr[]={-8,-3,4,-6,77,-88,101};
	int arr_size=6;

	bubble_sort( arr, arr_size );
	print_array( arr, arr_size );

return 0;

}
