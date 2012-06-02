#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void ending(int x,int y,char *s,char map[][100])
{
	char *turning="WNESWN";
	int position=1;
	int i;
	x--,y--;
	for (i=0;s[i]!='\0';i++)
	{
		if (s[i]=='R') position++;
		else if (s[i]=='L') position--;
		else if (s[i]=='F') 
		{
			if (turning[position]=='N' && map[x-1][y]!='*') x--;
			else if (turning[position]=='S' && map[x+1][y]!='*') x++;
			else if (turning[position]=='E' && map[x][y+1]!='*') y++;
			else if (turning[position]=='W' && map[x][y-1]!='*') y--;
		}
		if (position==0) position=4;
		else if (position==5) position=1;
	}
	cout<<x+1<<" "<<y+1<<" "<<turning[position]<<endl;
}

main()
{
	int x,y;
	char map[100][100];
	char s[10000];
	int i;
	int judge=1;
	int N;
	int j;
	cin>>N;
	for (j=1;j<=N;j++)
	{
		if (judge) judge=0;
		else cout<<endl;
		cin>>x>>y;
		cin.getline(s,10000,'\n');
		for (i=0;i<x;i++)
			cin.getline(map[i],100,'\n');
		cin>>x>>y;
		cin.getline(s,10000,'Q');
		ending(x,y,s,map);
	}
	return 0;
}











