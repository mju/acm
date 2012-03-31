#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <iomanip>

using std::setw;

void initial(int *p,int n)
{
	int i;
	p[n-1]=p[0]=0;
	for (i=1;i<n-1;i++)
		p[i]=1;
}

void allRight(int k,int m,int n)
{
	int i,j;
	int *p;
	int step;
	int a=n;
	int result;
	int result2;
	p=new int[n+2];
	initial(p,n+2);
	i=0,j=n+1;
	while (a>0)
	{
		step=0;
		result=k%a;
		if (!result) result=a;
		while (1)
		{
			if (p[i]) step++;
			if (step==result) break;
			i++;
			if (i>n) i=0;
		}
		step=0;
		result2=m%a;
		if (!result2) result2=a;
		while (1)
		{
			if (p[j]) step++;
			if (step==result2) break;
			j--;
			if (j<1) j=n+1;
		}
		if (j==i) a--,p[i]=0,cout<<setw(3)<<i;
		else a-=2,p[i]=p[j]=0,cout<<setw(3)<<i<<setw(3)<<j;
		if (a==0) cout<<endl;
		else cout<<",";
	}
}

main()
{
	int k,m,n;
	while (cin>>n>>k>>m && n || k || m)
		allRight(k,m,n);
	return 0;
}




