#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::cin;

int digit(double key)
{
	int i;
	for (i=1;key/10>=1;i++)
		key/=10;
	return i;
}

void putInteger(int **p,int n,double key)
{
	int i;
	int b=1;
	*p=new int[n];
	for (i=1;i<n;i++)
		b*=10;
	for (i=0;i<n;i++)
	{
		(*p)[i]=(int)key/b;
		key=key-(*p)[i]*b;
		b=b/10;
	}
}

int carrys(int *p,int *q,int n,int m)
{
	int i;
	int carry=0;
	int temp;
	int *asd,j,k,*sdf;
	if (n-m>0) i=m-1,asd=p,j=n-m-1,k=n-1,sdf=q;
	else i=n-1,asd=q,j=m-n-1,k=m-1,sdf=p;
	for (;i>=0;i--,k--)
	{
		temp=asd[k]+sdf[i];
		if (temp>=10 && k!=0)
			carry++,asd[k-1]++;
		else if (temp>=10 && k==0)
			carry++;
	}
	for (;j>=0;j--)
	{
		if (asd[j]>=10 && j!=0)
			asd[j-1]++,carry++;
		else if (asd[j]>=10 && j==0)
			carry++;
	}
	return carry;
}

main()
{
	double m,n;
	int a,b,c=0;
	int *p,*q;
	while (cin>>m>>n)
	{
		if (m==0 && n==0) break;
		a=digit(m);
		b=digit(n);
		putInteger(&p,a,m);
		putInteger(&q,b,n);
		c=carrys(p,q,a,b);
		if (c==0) cout<<"No carry operation."<<endl;
		else if (c==1) cout<<"1 carry operation."<<endl;
		else cout<<c<<" carry operations."<<endl;
	}
	return 0;
}



		



