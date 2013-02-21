/*WHAT PROG DOES :
 * 	Implements simple "hash table". Here to avoid "hash collision", "linear probing" has been used.
 *
 */

#include<stdio.h>
#include<limits.h>
#include"../array_functions.h"

#define TRUE 1
#define FALSE 0

int OVERFLOW_flag;

/***************************************************/
int hash_function( int arr_size , int value_to_insert ){
	if( value_to_insert < 0 )
		value_to_insert*=(-1);

	return ( value_to_insert % (arr_size+1) ) ;

}
/***************************************************/
void insert_into_arr( int *arr, int arr_size , int value_to_insert ){
	if( OVERFLOW_flag==TRUE ){
		printf("Array Full !! \n");
		return ;
	}

	int pos_to_insert=hash_function( arr_size , value_to_insert );

	/*check if pos_to_insert is "empty". If yes, fine.
	 * If no, then their is "collision" , so do "linear probing" to find next immediate empty position.
	 *
	 */
	printf("pos_to_insert : %d , value_to_insert: %d \n", pos_to_insert , value_to_insert );

	if( *(arr+pos_to_insert)  == INT_MAX ){
		*(arr+pos_to_insert)=value_to_insert ;
		return ;
	}
	

	printf("$$ \n");

	int current_pos=pos_to_insert;
	pos_to_insert= (pos_to_insert+1)%arr_size;

	for( ; current_pos!=pos_to_insert ; pos_to_insert++ )
		if( *(arr + (pos_to_insert%arr_size) )==INT_MAX ){
			*(arr+pos_to_insert)=value_to_insert ;
			printf("##New pos : %d \n", pos_to_insert );
			return ;
		}

	/*if we are here, it means array is full, so set the flag
	 */

	OVERFLOW_flag=TRUE;
	printf("Array Full !! \n");



}
/***************************************************/
void init_arr( int *arr , int arr_size ){
	int i;
	int *ptr=arr;
	/*intentionally using a ptr, coz operations with pointer are faster than array indexing .
	 */
	for(i=0 ; i<=arr_size ; i++,ptr++ )
		*ptr=INT_MAX;

	OVERFLOW_flag=FALSE;
}
/***************************************************/

int main(){
	int arr_size=3 ;

	int arr[arr_size];

	init_arr( arr, arr_size  );
	/*put INT_MAX in array, which indicate that the array positions are empty
	 */

	print_array( arr, arr_size );
	 
	insert_into_arr( arr , arr_size ,-41);
	insert_into_arr( arr , arr_size ,-44);
	insert_into_arr( arr , arr_size ,19);
	insert_into_arr( arr , arr_size ,95 );
	insert_into_arr( arr , arr_size ,22 );
	insert_into_arr( arr , arr_size ,20 );
	//search_into_arr( arr, num );
	print_array( arr, arr_size );


return 0;

}

