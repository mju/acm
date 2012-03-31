#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int process(int *p,char *s)
{
	int i,j;
	int sign;
	int summation;
	int check=1;
	for (i=0,j=0;s[i]!='\0';i++)
	{
		if (s[i]<='9' && s[i]>='0')
		{
			if (check) 
			{
				summation=0;
				if (s[i-1]=='-') sign=-1;
				else sign=1;
				check=0;
			}
			summation*=10;
			summation+=s[i]-'0';
		}
		else
		{
			check++;
			if (check==1) p[j]=summation*sign,j++;
		}		
	}
	p[j]=summation*sign,j++;
	return j;
}

void solve(int *p,int n,int *q,int m)
{
	int i,j,summation,multiply;
	for (i=0;i<n;i++)
	{
		summation=0,multiply=1;
		for (j=m-1;j>=0;j--)
		{
			summation+=q[j]*multiply;
			multiply*=p[i];
		}
		if (i!=0) cout<<" ";
		cout<<summation;
	}
	cout<<endl;
}

main()
{
	char s1[10000],s2[10000];
	int p[10000],q[10000];
	int n,m;
	while (cin.getline(s1,10000,'\n') && cin.getline(s2,10000,'\n'))
	{
		n=process(p,s2);
		m=process(q,s1);
		solve(p,n,q,m);
	}
	return 0;
}
	
