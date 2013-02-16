/* WHAT PROG DOES : 
 * Implements "Selection Sort" by finding min as well as max no in every pass & putting them at both the ends.
 *
 * NOTES : 
 * Dromey says this takes lesser no. of "comparisions" , I doubt this! How to prove/disprove ?
 *
 *
 */


#include<stdio.h>
#include"../array_functions.h"

/*********************************************************************/
void selection_sort( int *arr , int arr_size ){
	int *start , *end ,*ptr;

	int *global_min, *global_max;
	start=arr;
	end=arr+arr_size ;

	while( end-start > 0 ){
		printf("Start,end : %d %d \n", *start , *end );
		ptr=start;
		global_min=start;
		global_max=end;

		while(1){
			if( *ptr<*(ptr+1) ){
				if( *ptr<*global_min)
					global_min=ptr;

				if( *(ptr+1)>*global_max)
					global_max=ptr+1;

			}
			else{
				if( *(ptr+1)<*global_min)
					global_min=ptr+1;

				if( *(ptr)>*global_max)
					global_max=ptr;

			}

			if ( (ptr+1)==end || (ptr+2)==end ) break ;
			ptr+=2 ;
		}

		if( ptr+2 == end ){
			if( *end>*global_max ) global_max=end;
			else if ( *end<*global_min ) global_min=end;
		}

		int t;
		if( *start > *global_min )GENERIC_SWAP(*start,*global_min,t);
		if( *end < *global_max ) GENERIC_SWAP( *end, *global_max , t );

		
		start++;
		end--;

	}//end outer while 


}
/*********************************************************************/

int main(){
	int arr[]={2,2,2,7,2,7,9 };
	int arr_size=6;

	selection_sort( arr, arr_size );
	print_array( arr, arr_size );

return 0;

}
