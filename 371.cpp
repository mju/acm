#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int exist[1001];

void initial(void)
{
	int i;
	for (i=0;i<1001;i++) exist[i]=0;
}

unsigned int ackermann(unsigned int key)
{
	unsigned int count=0;
	if (key==1) return 3;
	while (key!=1)
	{
		if (key<1001) 
		{
			if (exist[key]!=0)
			{
				count+=exist[key];
				return count;
			}
		}
		if (key%2)
			key=key*3+1,count++;
		else key/=2,count++;
	}
	return count;
}

void process(void)
{
	exist[1]=3;
	int i;
	for (i=2;i<1001;i++)
		exist[i]=ackermann(i);
}

void swap(unsigned int &a,unsigned int &b)
{
	unsigned int c;
	c=a;
	a=b;
	b=c;
}

main()
{
	unsigned int L,H,max;
	unsigned int i;
	unsigned int record;
	unsigned int temp;
	initial();
	process();
	while (cin>>L>>H && L!=0 || H!=0)
	{
		max=0;
		if (L>H) swap(L,H);
		for (i=L;i<=H;i++)
		{
			temp=ackermann(i);
			if (temp>max) max=temp,record=i;
		}
		cout<<"Between "<<L<<" and "<<H<<", "<<record<<" generates the longest sequence of "<<max<<" values."<<endl;
	}
	return 0;
}


