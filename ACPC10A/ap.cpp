#include <cstdio>

using namespace std;

bool isAP( int array[] ) {
	if ( array[ 1 ] - array[ 0 ] == array[ 2 ] - array[ 1 ] ) {
		return true;
	}
	return false;
}

int main() {
	int array[ 3 ];
	while ( 1 ) {
		for ( int i = 0; i < 3; ++i ) {
			scanf( "%d", array + i );
		}
		if ( array[ 0 ] == 0 && array[ 1 ] == 0 && array[ 2 ] == 0 ) {
			break;
		}
		if ( isAP( array ) ) {
			printf( "AP %d\n", array[ 2 ] + ( array[ 2 ] - array[ 1 ] ) );
		}
		else {
			printf( "GP %d\n", array[ 2 ] * ( array[ 2 ] / array[ 1 ] ) );
		}
	}
	return 0;
}
