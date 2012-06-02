#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <cstdlib>

void initial(int *p,int n)
{
	int i;
	for (i=0;i<n;i++)
		p[i]=i;
}

long long count(int key,int key1)
{
	int i;
	long long j;
	int ture;
	int f,d,k;
	int *p;
	int *q;
	p=new int[key+1];
	initial(p,key+1);
	if (key-key1>key1) ture=key-key1,f=key1;
	else ture=key1,f=key-key1;
	q=new int[f+1];
	initial(q,f+1);
	d=f;
	while (d!=0)
	{
		for (i=key;i>=ture+1;i--)
		{
			if (!(p[i]%q[d]))
			{
				p[i]/=q[d],q[d]=1;
				break;
			}	
		}
		d--;
	}
	d=key;
	while (d!=ture)
	{
		for (i=f;i>=1;i--)
			if (q[i]%p[d]==0)
			{
				q[i]/=p[d],p[d]=1;
				break;
			}
		d--;
	}
	d=f;
	while (d!=0)
	{
		for (i=key;i>=ture+1;i--)
		{
			if (!(p[i]%q[d]))
			{
				p[i]/=q[d],q[d]=1;
				break;
			}	
		}
		d--;
	}
	j=1;
	for (i=ture+1;i<=key;i++)
		j*=p[i];
	for (i=1;i<=f;i++)
		if (j%q[i]==0) j/=q[i],q[i]=1;
	k=1;
	for (i=1;i<=f;i++)
		k*=q[i];
	return j/k;
}

main()
{
	int n,m;
	while (cin>>n>>m && n || m)
		cout<<n<<" things taken "<<m<<" at a time is "<<count(n,m)<<" exactly."<<endl;
	return 0;
}


