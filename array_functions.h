#define GENERIC_SWAP(a,b,temp){\
		temp=a;\
		a=b;\
		b=temp;\
}

void print_array( int arr[] , int arr_size ){
	int i=0 ;
	printf("[ ");
	for( i=0 ; i<=arr_size; i++ )
		printf("%d ", arr[i] );

	printf("]\n");

}
