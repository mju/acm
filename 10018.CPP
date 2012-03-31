#include <iostream>

using std::cout;
using std::cin;
using std::endl;

unsigned int countDigit(unsigned int key)
{
unsigned int i,j;
	for (i=1,j=1;key/j>=10;i++,j*=10);
	return i;
}

unsigned int reverse(unsigned int key)
{
	int w;
	int i;
	unsigned int z=1,j,y;
	int digit;
	unsigned int k;
	unsigned int f=0;
	unsigned int d;
	digit=countDigit(key);
	for (i=1;i<digit;i++)
		z=z*10;
	if (key<10) return key;
	for (i=digit,j=z,y=1;i>=1;i--,j/=10,y*=10)
	{
		k=key/j;
		if (i==digit)
			f=f+k;
		else
		{
			for (w=1,d=y;w<=digit-i;w++,d/=10)
				k=k%d;
			f=f+(k*y);
		}
	}
	return f;
}

main()
{
	int n;
	unsigned int key,c;
	int j;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>key;
		j=0;
		while (1)
		{
			j++;
			c=reverse(key);
			if (c==key && j==1) {}
			else if (c==key) break;
			key=key+c;
		}
		cout<<j-1<<" "<<key<<endl;
	}
	return 0;
}

