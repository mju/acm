#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void prepare(long double *p)
{
	int i;
	p[0]=0,p[1]=1;
	for (i=2;i<=50000;i++)
		p[i]=i+p[i-1];
}

long double count(int key,long double *p)
{
	return p[key]*p[key];
}

main()
{
	long double p[50001];
	int key;
	prepare(p);
	while (cin>>key)
	{
		cout.precision(26);
		cout<<count(key,p)<<endl;
	}
	return 0;
}

