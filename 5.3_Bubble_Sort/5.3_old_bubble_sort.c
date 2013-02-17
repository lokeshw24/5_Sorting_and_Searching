/*WHAT PROG DOES : 
 * Implements "bubble sort". Here things are very simple, we make exchanges during every iteration,
 * irrespective of if the array is sorted or not. So this is very inefficient.
 *
 */

#include<stdio.h>
#include"../array_functions.h"

/*********************************************************************/
void bubble_sort( int *arr , int arr_size ){
	int *first, *second, i ,j ;

	for( i=0 ; i<arr_size ; i++ ){
		first=arr;
		second=first+1;
		for( j=i; j<arr_size ; j++ ){
			if( *first>*second ){
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
	int arr[]={-8,-3,-4,-6,-77,-88,-101};
	int arr_size=6;

	bubble_sort( arr, arr_size );
	print_array( arr, arr_size );

return 0;

}
