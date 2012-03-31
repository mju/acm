#include <iostream>

using std::cout;
using std::cin;
using std::endl;

main()
{
	unsigned long long M_N; // M - N

	for ( cin >> M_N; M_N; cin >> M_N )
	{
		if ( M_N / 9 * 9 == M_N )
			cout << M_N * 10 / 9 -1 << ' ' << M_N * 10 / 9 << endl;
		else cout << M_N * 10 / 9 << endl;
	}

	return 0;
}