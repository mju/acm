#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void solve(const int &n)
{
	int *p;
	int q[6];
	int i;
	int position=5;
	p=new int[n];
	for (i=0;i<n;i++) cin>>p[i];
	for (i=0;i<6;i++) q[i]=i;
	while (q[0]<=n-6)
	{
		for (i=0;i<6;i++) 
			if (i==0) cout<<p[q[i]];
			else cout<<" "<<p[q[i]];
		cout<<endl;
		q[position]++;
		while (q[position]>=n && position>0)
		{
			q[--position]++;
			if (q[position]<n)
			{
				for (i=position+1;i<6;i++) q[i]=q[i-1]+1;
				position=5;
			}
		}
	}
}

main()
{
	int n;
	int judge=1;
	while (cin>>n && n)
	{
		if (judge) judge=0;
		else cout<<endl;
		solve(n);
	}
	return 0;
}

		

