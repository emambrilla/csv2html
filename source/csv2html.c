#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>

int main( int argc, char *argv[] ){

	char	caux[4096];
	char	*ptr, *ptr2, *ptr3;

	printf( "%s\n", "<!DOCTYPE html>" );
	printf( "\t%s\n", "<html>" );
	printf( "\t\t%s\n", "<table>" );
	printf( "\t\t\t%s\n", "<tbody>" );

	while ( fgets( caux, sizeof( caux ), stdin ) ) {
		printf( "\t\t\t\t%s\n", "<tr>" );
		if ( !(ptr=strstr( caux, ";" ) ) ) goto return_error;
		ptr[0]='\0';
		printf( "\t\t\t\t\t\t<td>%s</td>\n", caux );
		while ( (ptr2=strstr( ptr+1, ";" ) ) ) {
			ptr2[0]='\0';
			if ( (ptr3=strstr( ptr+1, ".") ) ) ptr3[0]=',';
			printf( "\t\t\t\t\t\t<td>%s</td>\n", ptr+1 );
			ptr=ptr2;
		} // while
		printf( "\t\t\t\t%s\n", "</tr>" );
	} // while

	printf( "%s\n", "<!DOCTYPE html>" );
	printf( "%s\n", "</tbody>" );
	printf( "%s\n", "</table>" );
	printf( "%s\n", "</html>" );


	return( 0 );

return_error:
	fprintf( stderr, "%s: error main\n", argv[0] );
	return( -1 );

} // main

