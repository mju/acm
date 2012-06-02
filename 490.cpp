#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void initial(int *p)
{
	int i;
	for (i=0;i<1000;i++)
		p[i]=-2;
}

int judge(int *p)
{
	int i;
	for (i=1;p[i]!=-2;i++)
		if (p[i]!=-3) return 0;
	return 1;
}

void show(char *a)
{
	int p[1000];
	int i,j;
	int length;
	initial(p);
	for (i=0;a[i]!='\0';i++) ;
	length=i-1;
	j=0;
	for (i=length;i>=0;i--)
		if (a[i]=='\n') p[j]=i,j++;
	p[j]=-1;
	while (1)
	{
		for (i=1;p[i]!=-2;i++) 
		{ 
			p[i]++;
			if (p[i]==-2)
			{
				p[i]=-3;
				continue;
			}
			if (a[p[i]]=='\n') p[i]=-3;
		}
		if (judge(p)) break;
		for (i=1;p[i]!=-2;i++) 
		{
			if (p[i]==-3) cout<<" ";
			else cout<<a[p[i]];
		}
		cout<<endl;
	}
}


main()
{
	char a[100000];
	cin.getline(a,10001,'\t');
	show(a);
	return 0;
}



			
			

