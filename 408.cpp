#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <iomanip>

using std::setw;

int GCD(int a,int b)
{
	if (b%a==0) return a;
	return GCD(b%a,a);
}

main()
{
	int a,b;
	while (cin>>a>>b)
	{
		cout<<setw(10)<<a<<setw(10)<<b;
		if (GCD(a,b)==1) cout<<"    Good Choice"<<endl;
		else cout<<"    Bad Choice"<<endl;
		cout<<endl;
	}
	return 0;
}







