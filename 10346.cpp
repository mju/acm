#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int calculate(int n,int k)//有n支香煙;k個煙屁股可以製成一支香煙
{
	int pepi=0;
	int total=0;
	while (n!=0 || pepi>=k)
		pepi+=n,total+=n,n=0,n=pepi/k,pepi=pepi%k;
	return total;
}

main()
{
	int n,k;
	while (cin>>n>>k)
		cout<<calculate(n,k)<<endl;
	return 0;
}
