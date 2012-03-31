#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void process(int *p)
{
	int i;
	int j;
	p[0]=0;
	p[1]=1;
	p[2]=1;
	for (i=3;i<1001;i++)
		if(i%2) p[i]=1;
		else p[i]=0;
	for (i=3;i<32;i+=2)
		for (j=i+1;j<1001;j++)
			if (j%i==0) p[j]=0;
}

void solve(int N,int C,int *p)
{
	int i,j;
	int k;
	int q[1000];
	cout<<N<<" "<<C<<":";
	for (i=1,j=0;i<=N;i++)
		if (p[i]) q[j]=i,j++;
	if (j%2)
	{
		if (2*C-1>=j)
		{
			for (i=0;i<j;i++) cout<<" "<<q[i];
			cout<<endl<<endl;
			return;
		}
		for (i=0;i<(j-(C*2)+1)/2;i++);
		for (k=1;k<=C*2-1;k++,i++) cout<<" "<<q[i];
	}
	else
	{
		if (2*C>=j)
		{
			for (i=0;i<j;i++) cout<<" "<<q[i];
			cout<<endl<<endl;
			return;
		}
		for (i=0;i<(j-(C*2))/2;i++);
		for (k=1;k<=C*2;k++,i++) cout<<" "<<q[i];
	}
	cout<<endl<<endl;
}

main()
{
	int N,C;
	int p[1001];
	process(p);
	while (cin>>N>>C)
		solve(N,C,p);
	return 0;
}