#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <cmath>

void initial(int *p)
{
	int i;
	int j;
	p[0]=p[1]=p[4]=p[6]=p[8]=p[9]=p[10]=0;
	p[2]=p[3]=p[5]=p[7]=1;
	for (i=11;i<10000;i++)
	{
		if (i%2==0 || i%3==0 || i%5==0 || i%7==0)
			p[i]=0;
		else p[i]=1;
	}
	for (i=11;i<101;i++) 
	{
		if (!p[i]) continue;
		for (j=i+1;j<10000;j++)
			if (j%i==0) p[j]=0;
	}
}

void solve(int key,int *p)
{
	int i;
	int j;
	int judge;
	for (i=3;i<=key/2;i+=2)
	{
		if (p[i])
		{
			judge=1;
			if (key-i<10000)
			{
				if (p[key-i])
				{
					cout<<key<<" = "<<i<<" + "<<key-i<<endl;
					return;
				}	
			}
			else
			{
				for (j=3;j<=sqrt(key-i);j+=2)
					if ((key-i)%j==0) 
					{
						judge=0;
						break;
					}
				if (judge) 
				{
					cout<<key<<" = "<<i<<" + "<<key-i<<endl;
					return;
				}
			}
		}
	}
	cout<<"Goldbach's conjecture is wrong"<<endl;
}

main()
{
	int key;
	int p[10000];
	initial(p);
	while (cin>>key && key)
		solve(key,p);
	return 0;
}



