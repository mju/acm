#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int yield(int *p,int n)
{
	unsigned int min;
	int i=0;
	while (1)
	{
		if (p[n/2+i]*2>p[n-1])
		{
			min=p[n/2+i]*2;
			break;
		}	
		i++;
	}
	i=0;
	while (1)
	{
		if (p[n/3+i]*3>p[n-1]) 
		{
			if (p[n/3+i]*3<min)
			{
				min=p[n/3+i]*3;
			}
			break;
		}
		i++;
	}
	i=0;
	while (1)
	{
		if (p[n/5+i]*5>p[n-1]) 
		{
			if (p[n/5+i]*5<min)
			{
				min=p[n/5+i]*5;
			}
			break;
		}
		i++;
	}
	i=0;
	while (1)
	{
		if (p[n/7+i]*7>p[n-1]) 
		{
			if (p[n/7+i]*7<min)
			{
				min=p[n/7+i]*7;
			}
			break;
		}
		i++;
	}
	return min;
}

void process(int *p)
{
	p[0]=0,p[1]=1;
	int i;
	for (i=2;i<=5842;i++) p[i]=yield(p,i);
}

main()
{
	int p[5843];
	int n;
	process(p);
	while (cin>>n && n)
	{
		if (n%10!=1 && n%10!=2 && n%10!=3 || n%100<=13 && n%100>=11)
			cout<<"The "<<n<<"th humble number is "<<p[n]<<"."<<endl;
		else if (n%10==1) cout<<"The "<<n<<"st humble number is "<<p[n]<<"."<<endl;
		else if (n%10==2) cout<<"The "<<n<<"nd humble number is "<<p[n]<<"."<<endl;
		else if (n%10==3) cout<<"The "<<n<<"rd humble number is "<<p[n]<<"."<<endl;
	}
	return 0;
}
	
