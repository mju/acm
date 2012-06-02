#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void input(int n,char p[][150])
{
	int i;
	for (i=1;i<=n;i++)
		cin>>(*(p+i)+1);
}

int count(int x,int y,char p[][150])
{
	int total=0;
	if (p[x-1][y-1]=='*') total++;
	if (p[x-1][y]=='*') total++;
	if (p[x-1][y+1]=='*') total++;
	if (p[x][y-1]=='*') total++;
	if (p[x][y+1]=='*') total++;
	if (p[x+1][y-1]=='*') total++;
	if (p[x+1][y]=='*') total++;
	if (p[x+1][y+1]=='*') total++;
	return total;
}

void process(int n,char p[][150])
{
	int i,j;
	for (i=1;i<=n;i++)
		for (j=1;p[i][j]!='\0';j++)
			if (p[i][j]=='.')
				p[i][j]=count(i,j,p)+'0';
}

void output(int n,char p[][150])
{
	int i;
	for (i=1;i<=n;i++)
		cout<<p[i]+1<<endl;
}
		
void initial(int x,int y,char p[][150])
{
	int i,j;
	for (i=0;i<x;i++)
		for (j=0;j<y;j++)
			p[i][j]='x';
}

main()
{
	char p[150][150];
	int x,y;
	int i=1;
	int judge=1;
	while (cin>>x>>y && x || y)
	{
		initial(x+2,y+2,p);
		input(x,p);
		process(x,p);
		if (judge) judge=0;
		else cout<<endl;
		cout<<"Field #"<<i<<":"<<endl;
		output(x,p);
		i++;
	}
	return 0;
}
