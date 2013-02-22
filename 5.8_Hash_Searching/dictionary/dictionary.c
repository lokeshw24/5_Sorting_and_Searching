#include"dictionary.h"

void init( node **dict ){
	*dict=NULL ;
}
/*********************************************************/
void print_node(node temp ){
	printf("[ %s = %s ] (%d) \n", temp.original_word, temp.meaning , temp.hash_key );
}
/*********************************************************/
void create_node( node *temp , char *word, char *meaning ){
	temp->next=NULL;
	temp->linear_chain=NULL;

	temp->original_word=word;
	temp->meaning=meaning;
	temp->hash_key=word[0]-'a';

}
/*********************************************************/
int insert_node_in_chain( node *master_node , node *temp ){
	/*here, we have a linear_chain starting with "front" , in which 
	 * we should "alphabetically" insert temp node.
	 * If there is a hash-collision, return -1 , else 0 
	 */
	node *front=master_node->next;


}
/*********************************************************/

void insert( node **dict , char *word, char *meaning ){

	/*firstly, create a node & then insert it into the dictionary */
	node *temp=(node *)malloc( sizeof(node) );
	create_node( temp , word , meaning );

	if( *dict==NULL ){
		*dict=temp;
		return ;
	}

	/*now keep on moving over the dictionary until you find a node with greater hash_key.
	 * Insert temp node at that position
	 */
	node *front , *back;
	back=*dict ;

	if( (*dict)->next == NULL )
		front=NULL;
	else{
		front=(*dict)->next;
		while(front && (front->hash_key)<(temp->hash_key) ){
			back=front;
			front=front->next;
		}

	}
	if(front->hash_key == temp->hash_key ){
		/*check if hash_key are same, if yes, insert in the linear_chain of that node */
		if( back->linear_chain == NULL ){
			back->linear_chain=temp;
			return ;
		}

		/*need to change the hash value of temp, so start from LHS, until first "non-identical"
		 * alphabet found.
		 */
		int alphabet_to_check=1;

		char *src=back->original_word;
		char *dest=temp->original_word;

		temp->hash_key=abs( src[alphabet_to_check] - dest[alphabet_to_check] );
		insert_node_in_chain( back , temp );
			

	}
	
	temp->next=back->next;
	back->next=temp;



}
/*********************************************************/
void print( dict d ){
	node *temp=d;
	while(d){
		printf("[ %s = %s ] (%d) \n", d->original_word , d->meaning, d->hash_key );
		d=d->next;
	}

}
/*********************************************************/

