#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void print(int head,int tail,char *s)
{
	int i;
	for (i=head+1;i<tail;i++)
		cout<<s[i];
}

void handle(char *a,char *b)
{
	int flag[5];
	int position=0;
	int i;
	for (i=0;a[i]!='\0';i++)
	{
		if (a[i]!='<' && a[i]!='>')
			cout<<a[i];
		else
		{
			flag[position]=i;
			position++;
		}
	}
	flag[4]=i;
	cout<<endl;
	for (i=0;b[i+3]!='\0';i++)
		cout<<b[i];
	print(flag[2],flag[3],a);
	print(flag[1],flag[2],a);
	print(flag[0],flag[1],a);
	print(flag[3],flag[4],a);
	cout<<endl;
}

main()
{
	char a[111];
	char b[111];
	int N,i;
	cin>>N;
	cin.getline(a,111,'\n');
	for (i=1;i<=N;i++)
	{
		cin.getline(a,111,'\n');
		cin.getline(b,111,'\n');
		handle(a,b);
	}
	return 0;
}
	


	
 