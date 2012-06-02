#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <cmath>

void initial(int *p)
{
	int i;
	for (i=2;i<100;i++)
		p[i]=1;
}

long long solve(int n,long long d)
{
	if (d<0) d*=-1;
	if (n==0 || n==1)
	{
		if (d==1) return 1;
		else return 0;
	}	
	int p[100];
	int i;
	int j;
	int k;
	int temp;
	long long result=1;
	initial(p);
	for (i=2;i<=n;i++)
	{
		temp=i;
		for (j=0;temp%2==0;temp/=2,j++);
		p[2]+=j;
		for (k=3;k<=sqrt(temp);k+=2)
		{
			for (j=0;temp%k==0;temp/=k,j++);
			p[k]+=j;
		}
		if (temp!=1) p[temp]++;
	}
	for (j=0;d%2==0;d/=2,j++);
	p[2]-=j;
	for (i=3;i<=sqrt(d);i+=2)
	{
		for (j=0;d%i==0;d/=i,j++);
		if (i>100) return 0;
		p[i]-=j;
	}
	if (d>100) return 0;
	if (d!=1) p[d]--;
	for (i=2;i<100;i++)
	{
		if (p[i]<1) return 0;
		result*=p[i];
	}
	return result;
}

main()
{
	int n;
	long long d;
	while (cin>>n>>d && n || d)
		cout<<solve(n,d)<<endl;
	return 0;
}






		



