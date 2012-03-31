#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

main()
{
	double a;
	int n,k;
	int i;
	while (cin>>n>>k)
	{
		if (n-k<k) k=n-k;
		a=0.0;
		for (i=0;i<k;i++)
			a+=log10((double)(n-i));
		for (i=1;i<=k;i++)
			a-=log10((double)(i));
		cout<<(int)(a+1.0)<<endl;
	}	
	return 0;
}
	

