#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#define	SIZE	50

void Fibonacci( unsigned int *a )
{
	int i;

	a[0] = 1;
	a[1] = 2;
	
	for ( i = 2; i < SIZE; i++ )
		a[ i ] = a[ i - 1 ] + a[ i - 2 ];

}

main()
{
	int N;
	unsigned int a[ SIZE ];
	unsigned int numberOfMale;
	unsigned int total;

	Fibonacci( a );

	for ( cin >> N; N != -1; cin >> N )
	{
		total = 2; // The immortal female bee, and the last male bee
		numberOfMale = 1; // The last male bee

		for ( N--; N  > 0; N-- )
			total += a[ N ], numberOfMale += a[ N - 1 ];

		if ( N == -1 ) cout << "0 1" << endl;
		else cout << numberOfMale << ' ' << total << endl;
	}

	return 0;
}