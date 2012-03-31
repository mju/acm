#include <iostream>

using std::cout;
using std::cin;
using std::endl;

main()
{
	int judge;
	int n;
	int howmany;
	int length;
	int temp;
	int i,j,k,l;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>length>>howmany;
		judge=1;
		for (j=1;j<=howmany;j++)
		{
			if (judge) judge=0;
			else cout<<endl;
			temp=length;
			for (k=1;k<=length;k++)
			{
				for (l=1;l<=k;l++) cout<<k;
				cout<<endl;
				if (k+1>temp) temp--,k-=2;
				if (k==-1) break;
			}
		}
	}
	return 0;
}

			
