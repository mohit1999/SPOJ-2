#include <cstdio>

using namespace std;

struct bignum {
	int data[ 1000 ];
	int len;
};

void init( bignum &a ) {
	a.len = 0;
	for ( int i = 0; i < 1000; ++i ) {
		a.data[ i ] = 0;
	}
}

bignum makeBignum( long long int num, int pos ) {
	bignum a;
	init( a );
	if ( num == 0 ) {
		a.len = 1;
		a.data[ 999 ] = 0;
		return a;
	}
	int i;
	int len = 0;

	for ( i = 999 - pos; num != 0; --i ) {
		a.data[ i ] = num % 10;
		num = num / 10;
		++len;
	}
	a.len = len + pos;
	return a;
}

bignum add( bignum a, bignum b ) {
	bignum c;
	int min, max;
	if ( a.len >= b.len ) {
		max = a.len;
	}
	else {
		max = b.len;
	}
	init( c );
	int sum, rem = 0, save, len = 0;
	int i;


	for ( i = 999; i >= 1000 - max; --i ) {
		sum = a.data[ i ] + b.data[ i ];
		sum += rem;
		rem = sum / 10;
		sum %= 10;
		c.data[ i ] = sum;
		++len;
	}
	if ( rem != 0 ) {
		++len;
		c.data[ i ] += rem;
	}
	c.len = len;
	return c;
}

void print( bignum a ) {
	int sum = 0;
	for ( int i = 1000 - a.len; i < 1000; ++i ) {
		printf( "%d", a.data[ i ] );
	}
	printf( "\n" );
}

bignum mult( bignum a, bignum b ) {
	bignum c, d;
	init( c );
	init( d );
	int i, j, k = 0, n = 0;
	int rem;
	for ( i = 999; i >= 1000 - a.len; --i ) {
		for ( j = 999; j >= 1000 - b.len; --j, ++k ) {
			init( c );
			int num = a.data[ i ] * b.data[ j ];
			int pos = 999 - k;
			while ( num > 0 ) {
				c.data[ pos ] = num % 10;
				num /= 10;
				--pos;
			}
			c.len = 999 - pos;
			if ( c.len == 1 && c.data[ 999 ] == 0 ) ;
			else {
				d = add( d, c );
			}
		}
		k = n + 1;
		n = k;
	}
	return d;
}

int main() {
	bignum a, b;
	int N, num;
	scanf( "%d", &N );
	while ( N > 0 ) {
		scanf( "%d", &num );
		init( a );
		init( b );
		a = makeBignum( num, 0 );
		for ( int i = num - 1; i > 1; --i ) {
			b = makeBignum( i, 0 );
			a = mult( a, b );
		}
		print( a );
		--N;
	}
	bignum d = mult( makeBignum( 25, 0 ), makeBignum( 25, 0 ) );
	print( d );
	return 0;
}
