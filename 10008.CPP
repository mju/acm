#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void count(int *p,char *a,int &max)
{
	int i;
	for (i=0;a[i]!='\0';i++)
	{
		if (a[i]>='a' && a[i]<='z')
			a[i]=a[i]-'a'+'A';
		if (++p[a[i]]>max)
			max=p[a[i]];
	}
}

void initial(int n,int *p)
{
	int i;
	for (i=0;i<n;i++)
		p[i]=0;
}

void print(int n,int *p,int max)
{
	int i,j;
	for (i=max;i>0;i--)
		for (j=0;j<n;j++)
			if (p[j]==i && j>='A' && j<='Z')
				cout<<(char)j<<" "<<i<<endl;
}

main()
{
	char a[1000];
	int p[130];
	int m;
	int i;
	int max;
	max=0;
	initial(130,p);
	cin>>m;
	for (i=0;i<=m;i++)//多繞依次因為輸入m的時候的\n也彙被讀進去
	{
		cin.getline(a,1000,'\n');
		count(p,a,max);
	}
	print(130,p,max);
	return 0;
}

	
		

