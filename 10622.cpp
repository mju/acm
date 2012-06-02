#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <cmath>

int gcd(int a,int b)
{
	if (a==0) return b;
	return gcd(b%a,a);
}

int solve(int key)
{
	int temp;
	int position=0;
	int exponent[30];
	int judge2;
	int judge=0;
	int i,j;
	if (key<0) key*=-1,judge=1;
	for (i=0;key%2==0;++i,key/=2);
	if (i) exponent[position++]=i;
	for (i=3;i<=sqrt(key);i+=2)
	{
		for (j=0;key%i==0;j++,key/=i);
		if (j) exponent[position++]=j;
	}
	if (key>1) exponent[position++]=1;
	if (position>1) temp=gcd(exponent[0],exponent[1]);
	else if (judge && exponent[0]%2==0)
	{
		while (exponent[0]%2==0) exponent[0]/=2;
		return exponent[0];
	}
	else return exponent[0];
	for (i=temp;i>=1;i--)
	{
		for (j=0,judge2=0;j<position;j++)
			if (exponent[j]%i) judge2=1;
		if (!judge2) break;
	}
	if (judge && i%2==0)
	{
		while (i%2==0) i/=2;
		return i;
	}
	return i;
}

main()
{
	int key;
	while (cin>>key && key)
		cout<<solve(key)<<endl;
	return 0;
}

		



