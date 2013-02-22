/*WHAT PROG DOES :
 * 	Implements simple "hash table". Here to avoid "hash collision", "linear probing" has been used.
 *
 * NOTE :
 * 	arr_size : is the position of the last element of an array, and not the total no. of element in an array.
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
	

	printf("$$Collision, so lets do linear probing  \n");

	int current_pos=pos_to_insert;
	//pos_to_insert= (pos_to_insert+1)%(arr_size+1);
	int i=0;

	for( ++pos_to_insert ; current_pos!=pos_to_insert && i<4; i++,pos_to_insert++ ){
		printf("pos_to_insert, arr[pos_to_insert], current_pos: %d %d %d \n", pos_to_insert%(arr_size+1) , *(arr + (pos_to_insert%(arr_size+1) ) ) , current_pos  );
		pos_to_insert=pos_to_insert%(arr_size+1);

		if( *(arr + pos_to_insert)==INT_MAX ){
			*(arr+pos_to_insert)=value_to_insert ;
			printf("##New pos : %d \n", pos_to_insert );
			return ;
		}
	}

	/*if we are here, it means array is full, so set the flag
	 */

	OVERFLOW_flag=TRUE;
	printf("Array Full !! \n");



}
/***************************************************/
int search_into_arr( int arr[] , int arr_size , int value_to_search ){
	int pos_to_search=hash_function( arr_size , value_to_search);

	if( *(arr+pos_to_search) == value_to_search ) return pos_to_search;
	
	/*else,now do linear probing, until u find the value OR one loop of array is complete OR 
	 * INT_MAX is found.
	 */
	int current_pos=pos_to_search;

	for( ++pos_to_search ; current_pos!=pos_to_search ; pos_to_search++ ){
		//printf("pos_to_search, arr[pos_to_search] : %d %d \n", pos_to_search%(arr_size+1) , *(arr + (pos_to_search%(arr_size+1) ) ) );
		pos_to_search=pos_to_search%(arr_size+1);
		if( *(arr+pos_to_search) == INT_MAX ){
			printf("$$Nos doesnt exist !! \n");
			return -1 ;
		}

		if( *(arr + pos_to_search)== value_to_search ){
			return pos_to_search;
		}
	}
	printf("Nos doesnt exist !! \n");
	return -1 ;


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
	int arr_size=7 ;
	int t=arr_size+1;

	int arr[t];
	int values[]={ 5,2,6,3};

	init_arr( arr, arr_size  );
	/*put INT_MAX in array, which indicate that the array positions are empty
	 */

	print_array( arr, arr_size );

	int i;
	for(i=0 ; i<4; i++ ){
		insert_into_arr(arr, arr_size , values[i] );
		print_array(arr, arr_size );
		printf(" \n\n");
	}
	 
	int value_to_search=4;
	printf("Srch position :%d \n",search_into_arr( arr , arr_size , value_to_search ) );


return 0;

}

