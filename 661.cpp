#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void initial(int *r,int n)
{
	for (int i=0;i<n;i++)
		r[i]=0;
}

main()
{
	int n;//有多少個電器
	int m;//有幾次開關動作
	int c;//保險司的最高負荷
	int *p;//n
	int *q;//m
	int *r;//check;n
	int i;
	int j;
	int f;//電流的summation
	int maxf;

	for (i=1;cin>>n>>m>>c;i++)
	{
		if (n==0 && m==0 && c==0)
			break;
		p=new int[n];
		q=new int[m];
		r=new int[n];
		f=0;
		maxf=0;
		initial(r,n);

		for (j=0;j<n;j++)
			cin>>p[j];
		for (j=0;j<m;j++)
			cin>>q[j];

		for (j=0;j<m;j++)
		{
			if (r[q[j]-1]==0)
			{
				f+=p[q[j]-1];
				r[q[j]-1]=1;
				if (f>c) break;
			}
			else
			{
				f-=p[q[j]-1];
				r[q[j]-1]=0;
			}
			if (f>maxf) maxf=f;
		}
		if (j<m)
			cout<<"Sequence "<<i<<'\n'<<"Fuse was blown."<<endl;
		else
			cout<<"Sequence "<<i<<'\n'<<"Fuse was not blown."<<'\n'
				<<"Maximal power consumption was "<<maxf<<" amperes."<<endl;
		cout<<endl;

		delete [] q;
		delete [] p;
		delete [] r;
	}
	return 0;
}





		
