#define GENERIC_SWAP(a,b,temp){\
		temp=a;\
		a=b;\
		b=temp;\
}

void print_array( int arr[] , int arr_size ){
	/*NOTE : arr_size is the position of the last element in an array.
	 * And not the total no. of elements in an array.
	 */
	int i=0 ;
	arr_size++;

	printf("[ ");
	for( i=0 ; i<arr_size; i++ )
		printf("%d ", arr[i] );

	printf("]\n");

}
