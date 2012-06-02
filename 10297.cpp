#include <iostream>

using std::cout;
using std::endl;
using std::cin;

#define PI 3.141592653589

#include <cmath>

main()
{
	int D,V;
	while (cin>>D>>V)
	{
		if (!D && !V) break;
		cout.precision(5);
		cout<<pow(D*D*D-(6.0*V/PI),1.0/3.0)<<endl;
	}
	return 0;
}

	