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
	int i,j,count=0;
	for (i=n-1;i>0;i--)
		for (j=1;j<=i;j++)
			if (p[j-1]>p[j])
			{
				swap(p[j-1],p[j]);
				count++;
			}
	return count;
}

main()
{
	int n,i,*p;
	while (cin>>n)
	{
		p=new int[n];
		for (i=0;i<n;i++) cin>>p[i];
		cout<<"Minimum exchange operations : "<<bbsort(p,n)<<endl;
		delete [] p;
	}
	return 0;
}