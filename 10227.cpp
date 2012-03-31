#include <iostream>

using std::cout;
using std::cin;
using std::endl;

main()
{
	int *p;
	int i,j;
	int n;
	int T,P;
	int count;
	int temp;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		count=0;
		cout<<endl;
		cin>>P>>T;
		p=new int[T];
		for (j=0;j<T;j++)
			p[j]=0;
		while (cin>>P>>temp)
			p[temp-1]++;
		for (j=0;j<T;j++)
			if (p[j]%2==1)
				count++;
		cout<<count<<endl;
	}
	return 0;
}
	