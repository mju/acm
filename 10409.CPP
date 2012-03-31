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

void north(int *p)
{
	swap(p[0],p[2]);
	swap(p[2],p[5]);
	swap(p[2],p[4]);
}

void south(int *p)
{
	swap(p[0],p[5]);
	swap(p[5],p[2]);
	swap(p[4],p[5]);
}

void west(int *p)
{
	swap(p[1],p[2]);
	swap(p[2],p[3]);
	swap(p[3],p[5]);
}

void east(int *p)
{
	swap(p[1],p[2]);
	swap(p[3],p[5]);
	swap(p[1],p[3]);
}

main()
{
	char s[6];
	int *p;
	int N;
	int i;
	while (cin>>N && N)
	{
		p=new int[6];
		p[0]=2,p[1]=3,p[2]=1,p[3]=4,p[4]=5,p[5]=6;
		for (i=1;i<=N;i++)
		{
			cin>>s;
			if (strcmp(s,"north")==0) north(p);
			else if (strcmp(s,"south")==0) south(p);
			else if (strcmp(s,"west")==0) west(p);
			else if (strcmp(s,"east")==0) east(p);
		}
		cout<<p[2]<<endl;
	}
	return 0;
}







