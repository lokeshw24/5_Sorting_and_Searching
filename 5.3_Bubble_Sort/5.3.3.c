/*WHAT PROG DOES : 
 * Implements __modified__ "bubble sort". Here in order to keep balance/symmetry we do the iterations in
 * alternating directions. This "quickly" makes the array sorted.
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

	for( i=0 ; i<arr_size && sorted==FALSE ; i+=2 ){
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

		j--;
		second=arr+j;
		first=second-1;


		for( ; j>0 ; j--){
			if( *first>*second ){
				sorted=FALSE;
				int t=*first;
				*first=*second;
				*second=t;
			}
			first--;
			second--;
		}



	}//end for


}
/*********************************************************************/

int main(){
	int arr[]={2,-2};
	int arr_size=1;

	bubble_sort( arr, arr_size );
	print_array( arr, arr_size );

return 0;

}
