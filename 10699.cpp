#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <cmath>

void initial(int *p)
{
	int i;
	p[1]=0;
	p[2]=1;
	for (i=3;i<1001;i+=2)
		p[i]=1,p[i+1]=0;
}

void process(int *p)
{
	int i,j;
	initial(p);
	for (i=3;i<=31;i+=2)
		for (j=i+2;j<1001;j+=2)
			if (p[j] && j%i==0) p[j]=0;
}

bool TestPrime(const int &key)
{
	int i;
	if (key%2==0) return 0;
	for (i=3;i<=sqrt(key);i+=2)
		if (key%i==0) return 0;
	return 1;
}
	
int calculate(const int &key,int *p)
{
	int i;
	int times=0;
	for(i=2;i<=sqrt(key);i++)
		if (key%i==0)
		{
			if (p[i]) times++;
			if (TestPrime(key/i) && key/i!=i) times++;
		}
	if (!times) 
	{
		if (key<1001 && p[key]) times++;
		else if (key>1001 && TestPrime(key)) times++;
	}
	return times;
}

main()
{
	int key;
	int p[1001];
	process(p);
	while (cin>>key && key)
		cout<<key<<" : "<<calculate(key,p)<<endl;
	return 0;
}





 