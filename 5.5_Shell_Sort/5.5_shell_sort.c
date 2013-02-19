/*WHAT PROG DOES : 
 * Implements standard "Shell Sort". Here we used "Insertion Sort" for sorting in the "chains" with the jump_factor.
 *
 */


#include<stdio.h>
#include"../array_functions.h"

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


			if( *start>*next ){
				GENERIC_SWAP( *start, *next, t);
			}
			while( next+jump_factor <= EOA ){
				start+=jump_factor ;
				next+=jump_factor ;

				if( *start>*next ) {
					/*do "insertion_sort" on chain of 'jump_factor' 
					 */
					int *temp=start;
					while( temp>(arr+i) && *temp>*next )
						temp-=jump_factor;

					int remember_next_val=*next ;
					int *remember_next_ptr=next;
					while( start>temp ){
						*next=*start;
						next=start;
						start-=jump_factor;
					}
					*next=remember_next_val;

					/*reset the start and next pointers */
					next=remember_next_ptr;
					start=next-jump_factor;



				}//end if

			}//end inner while


		}//end for 


		jump_factor/=2 ;
	}//end while 

	


}
/*********************************************************/
int main(){
	int arr[]={14,-35,-3,8,20,-41,12, -39};
	int arr_size=7;

	shell_sort( arr, arr_size );
	print_array( arr, arr_size );

return 0;

}

