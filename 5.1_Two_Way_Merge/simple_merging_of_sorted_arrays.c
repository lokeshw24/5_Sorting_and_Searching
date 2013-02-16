/*Prog that takes 2 sorted arrays and "merges" them
 *
 * NOTES :
 * 1.Everywhere "arr_size" indicates length of array from 0 to arr_size ie if arr_size=5 , then there are 6 elements in it.
 *
 * TO_DO :
 * 1.Test the program's correctness by giving it many random i/p. Write script doing so.
 *
 */


#include<stdio.h>

void merge_already_sorted_arrays( int *arr1 , int end_of_arr1 , int *arr2, int end_of_arr2 , int *new_sorted_arr ){
	int count_arr1=0;
	int count_arr2=0;

	while(1){
		if( *arr1 < *arr2 ){
			*new_sorted_arr++=*arr1 ;
			count_arr1++;
			if(count_arr1>end_of_arr1) 
				break;
			arr1++;
		}
		else{
			*new_sorted_arr++=*arr2 ;
			count_arr2++;
			if(count_arr2>end_of_arr2) 
				break;
			arr2++;
		}
		
	}


	if( count_arr1>end_of_arr1 ){
		for( ;  count_arr2<end_of_arr2 ; count_arr2++ ){
			*new_sorted_arr++=(*arr2++);
		}
		*new_sorted_arr=*arr2;
	}
	else{
		for( ;  count_arr1<end_of_arr1 ; count_arr1++ )
			*new_sorted_arr++=(*arr1++);
		*new_sorted_arr=*arr1;
	}

}
/*************************************************************************/
void print_array( int arr[] , int arr_size ){
	int i=0 ;
	for( i=0 ; i<=arr_size; i++ )
		printf("%d ", arr[i] );

}
/*************************************************************************/
int main(){
	int arr1[]={2,4,5,13,16,23} ;
	int arr2[]={-2,7,10,17,36,44, 233 ,323} ;

	int new_sorted_arr[14];

	merge_already_sorted_arrays( arr1,5,arr2,7, new_sorted_arr );
	print_array( new_sorted_arr , 13 );

return 0;

}
