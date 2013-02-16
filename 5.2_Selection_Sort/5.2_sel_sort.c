/* WHAT PROG DOES : 
 * Simple Prog doing "Selection Sort", sorts nos in ascending order
 *
 * NOTES : 
 * Here I have included one function stored in common file in previous folder, which I intend to use everywhere.
 * Will have to find out how exactly things happen "practically", probably "make" file etc
 *
 *
 */


#include<stdio.h>
#include"../array_functions.h"

/*********************************************************************/
void selection_sort( int *arr , int arr_size ){
	int *first, *last ,*curr_min ,*temp, i,j ;
	first=arr;

	for( i=0,j=1; i<arr_size ; i++,first++ ){
		temp=first;
		last=first+1;

		for( j=i+1 ; j<arr_size ; j++, last++ ){
			if( *last<*temp )
				temp=last;
		}
		if( *last<*temp )
			temp=last;

		if( *temp<*first ){
			int t=*temp;
			*temp=*first;
			*first=t;
		}

	}//end for 

}
/*********************************************************************/

int main(){
	int arr[]={3,4,3,4,3,4,3,4,3};
	int arr_size=8;

	selection_sort( arr, arr_size );
	print_array( arr, arr_size );

return 0;

}
