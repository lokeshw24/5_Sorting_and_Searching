/*WHAT PROG DOES : 
 * Implements standard "Shell Sort". Here we used "Bubble Sort" for sorting in the "chains" with the jump_factor.
 *
 */


#include<stdio.h>
#include"../array_functions.h"

#define TRUE 1
#define FALSE 0

/*********************************************************/
void shell_sort( int *arr, int arr_size ){
	int no_arr_elements=arr_size+1;
	int jump_factor=no_arr_elements/2;
	int *EOA=arr+arr_size ;

	int i,j,t ;

	int *start;
	while( jump_factor>0 ){
		for( i=0 ; i<jump_factor ; i++){
			start=arr+i ;
			int *next=start+jump_factor;

			/*now do "bubble sort on the chains of 'jump_factor' 
			 */
			int sorted=FALSE;

			while(1){
				sorted=TRUE ;

				while(1){
					if( *start>*next ) {
						printf("$$ \n");
						GENERIC_SWAP(*start , *next , t );
						sorted=FALSE;

					}//end if
					start+=jump_factor ;
					if( next+jump_factor <= EOA )next+=jump_factor ;
					else break ;
				}
				if( arr+i+jump_factor+jump_factor <= EOA && sorted==FALSE ){
					start=arr+i+jump_factor;
					next=start+jump_factor;
				}
				else break ;

			}//end outer while

		}//end for 

		jump_factor/=2 ;
	}//end while 

	


}
/*********************************************************/
int main(){
	int arr[]={3,3,3,-3,3,-3,3, 3} ;
	int arr_size=7;

	shell_sort( arr, arr_size );
	print_array( arr, arr_size );

return 0;

}

