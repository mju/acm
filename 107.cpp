#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <cmath>

int exponent(int &a,int &b)
{
	int i,j;
	for (i=1;i<=b;i++)
		for (j=1;pow(i+1,j)<=a;j++)
			if (pow(i+1,j)==a && pow(i,j)==b)
			{
				a=i+1,b=i;
				return j;
			}
}

void count(int &a,int &b)
{
	int exp;
	exp=exponent(a,b);
	//cout<<a<<" "<<b<<endl;
	int i,j;
	int total=0;
	int total1=0;
	for (i=1,j=pow(a,exp);j>1;i*=b,j/=a)
		total+=i,total1+=i*j;
	total1+=i;
	a=total;
	b=total1;
}

main()
{
	int a,b;
	while (cin>>a>>b && a || b)
	{
		count(a,b);
		cout<<a<<" "<<b<<endl;
	}
	return 0;
}








