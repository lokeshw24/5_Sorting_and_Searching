/* WHAT PROG DOES : 
 * Simple Prog doing "Selection Sort", that removes duplicates during the sorting process.
 * Output is ascending sorted nos.
 *
 */


#include<stdio.h>
#include"../array_functions.h"

#define GENERIC_SWAP(a,b,temp){\
	temp=a;\
	a=b;\
	b=temp;\
}


/*********************************************************************/
int selection_sort( int *arr , int arr_size ){
	int *first, *last ,*curr_min ,*temp, i,j ;
	first=arr;

	int *EOA=arr+arr_size;
	/*EOA = End Of Array */

	for( ; (EOA-first)>0  ; ){
		temp=first;
		last=first+1;
		while( *first==*last && first!=EOA ) {
			int t;
			GENERIC_SWAP( *last,*EOA,t );
			EOA--;

		}


		for(  ; (EOA-last)>0  ; last++ ){
			if( *last<*temp )
				temp=last;
		}
		if( *last<*temp )
			temp=last;
		/*At this stage, we can swap first & temp. BUT now we will check if it is a duplicate.
		 * If not, then go ahead , else put the duplicate at the end of array & reduce EOA
		 */

		if( *temp<*first  ){
			if( *temp!=*(first-1)  ){
			/*so not a duplicate, go ahead & swap bindass ! 
			 */
				int t;
				GENERIC_SWAP(*temp,*first,t);
			}
			else{
				int t;
				GENERIC_SWAP( *temp,*EOA,t );
				EOA--;
				continue;
			}

		}
		first++;

	}//end for 

	return ( EOA-arr );

}
/*********************************************************************/

int main(){
	int arr[]={2,2,2,2};
	int arr_size=3;

	int new_arr_size = selection_sort( arr, arr_size );
	print_array( arr, new_arr_size );

	printf("No. of Duplicates found are : %d \n", arr_size-new_arr_size );
return 0;

}
