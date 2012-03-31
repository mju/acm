#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void swap(int &a,int &b)
{
	int c;
	c=a;
	a=b;
	b=c;
}

int bbsort(int *p,int n)
{
	int i,j;
	int times=0;
	for (i=n-1;i>0;i--)
		for (j=1;j<=i;j++)
			if (p[j]<p[j-1])
			{
				swap(p[j],p[j-1]);
				times++;
			}
	return times;
}

main()
{
	int N;
	int i;
	int *p;
	int k;
	int n;
	cin>>N;
	for (k=1;k<=N;k++)
	{
		cin>>n;
		p=new int[n];
		for (i=0;i<n;i++) 
			cin>>p[i];
		cout<<"Optimal train swapping takes "<<bbsort(p,n)<<" swaps."<<endl;
	}
	return 0;
}

















