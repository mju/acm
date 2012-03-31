#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <iomanip>

using std::setw;

main()
{
	unsigned long n=6,k=8,a,b;
	unsigned long times=0;
	while (times<10)
	{
		cout<<setw(10)<<n<<setw(10)<<k<<endl;
		a=n,b=k;
		n=3*a+2*b+1;
		k=4*a+3*b+1;
		times++;
	}
	return 0;
}








			
			

