#include <iostream>

using std::cout;
using std::cin;
using std::endl;

bool rectangle(double x,double y,double *p)
{
	//cout<<*p<<endl;
	if (x>*p && y<*(p+1) && x<*(p+2) && y>*(p+3)) return 1;
	return 0;
}

bool circle(double x,double y,double *p)
{
	double a;
	double b,c;
	a=x-(*p);
	c=*(p+2);
	b=y-(*(p+1));
	if (a*a+b*b<c*c) return 1;
	return 0;
}

main()
{
	double data[40];
	char figure[10];
	int i,j;
	int position=0;
	double x,y;
	bool judge;
	for (i=0;;i++)
	{
		cin>>figure[i];
		if (figure[i]=='*') break;
		if (figure[i]=='r')
		{
			for (j=1;j<=4;j++,position++)
				cin>>data[position];
		}
		else if (figure[i]=='c')
		{
			for (j=1;j<=3;j++,position++)
				cin>>data[position];
		}
	}
	i=1;
	while (cin>>x>>y && x!=9999.9 || y!=9999.9)
	{
		position=0;
		judge=1;
		for (j=0;figure[j]!='*';j++)
		{
			if (figure[j]=='r')
			{
				position+=4;
				if (rectangle(x,y,data+position-4))
				{
					judge=0;
					cout<<"Point "<<i<<" is contained in figure "<<j+1<<endl;
					continue;
				}
			}
			else if (figure[j]=='c')
			{
				position+=3;
				if (circle(x,y,data+position-3))
				{
					judge=0;
					cout<<"Point "<<i<<" is contained in figure "<<j+1<<endl;
					continue;
				}
			}
		}
		if (judge) cout<<"Point "<<i<<" is not contained in any figure"<<endl;
		i++;
	}
	return 0;
}
		