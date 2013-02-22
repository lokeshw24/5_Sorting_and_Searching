#include"dictionary.h"


int main(){
	char word[]="allude";
	char meaning[]="to run away" ;

	dict d;
	init( &d );
	insert( &d , word, meaning );
	insert( &d , "lokesh" , "obsessed" );
	insert( &d , "bhosari" , "birth-place" );
	insert( &d , "zenith" , "highest_point" );

	print( d );

return 0;

}
	
