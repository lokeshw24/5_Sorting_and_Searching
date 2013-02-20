/*WHAT PROG DOES :
 * Count the avg "shift" of an element from its original position after getting sorted.
 * Here in order to have a count for each element, I m putting the every element in a node,
 * and maintaining a counter for everyone.
 *
 */

#include<stdio.h>
#include"../array_functions.h"

/*********************************************************************/
typedef struct abc{
	int num;
	int count;
}node ;

void init_nodes( node *array_ptr , int *original_arr , int arr_size ){
	int i;
	for( i=0 ; i<=arr_size ; i++ ){
		array_ptr[i].num=original_arr[i];
		array_ptr[i].count=0;

	}

}

void print_nodes( node array_ptr[], int arr_size ){
	int i;
	printf(" [ " );
	for(i=0 ; i<=arr_size ; i++ )
		printf(" %d(%d) ", array_ptr[i].num, array_ptr[i].count );

	printf("] \n" );

}

/*********************************************************************/
void insertion_sort( node *array_ptr , int arr_size ){
	int i, last_cou;
	
	for( i=1 ; i<=arr_size ; i++ ){
		node *last=array_ptr+i;
		node *first=array_ptr;
		node tt;

		while( first!=last ){
			if( (first->num) > (last->num) ){

				tt.num=last->num;
				tt.count=last->count;

				node *temp=last-1;
				last_cou=0;
				while(temp!=first){
					(temp->count)++;
					/*now swap 2 nodes */
					((temp+1)->num)=((temp)->num);
					((temp+1)->count)=((temp)->count);
					/*done with swapping */

					--temp;
					++last_cou ;
				}
				/*now , for one last time....swap 2 nodes */
				(temp->count)++;
				((temp+1)->num)=((temp)->num);
				((temp+1)->count)=((temp)->count);
				/*done with swapping */
				
				first->num=tt.num;
				first->count=tt.count-(last_cou+1) ;

			}
			first++;
		}//end while


	}//end for
}
/*********************************************************************/

int main(){
	int arr[]={-9,33,-222};
	int arr_size=2;
	node array_nodes[arr_size];

	init_nodes( array_nodes , arr, arr_size );
	print_nodes( array_nodes , arr_size );

	insertion_sort( array_nodes , arr_size );

	/*Make -ve values +ve */
	int i, temp ;
	for(i=0 ; i<=arr_size ; i++ )
		if( array_nodes[i].count < 0 )
			array_nodes[i].count*=(-1) ;

	print_nodes( array_nodes , arr_size );

	/*now lets find the avg distance travelled by every element */
	for( i=0,temp=0 ; i<=arr_size ; i++ )
		temp+=array_nodes[i].count ;

	printf("Avg dist travelled by every element : %f \n", (float)temp/arr_size );

return 0;

}
