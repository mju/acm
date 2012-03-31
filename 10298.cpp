#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int judge(char *s,int length,int b)
{
	int i,j;
	if (s[length-1]!=s[b-1]) return 0;
	for (i=length,j=0;s[i]!='\0';i++,j++)
		if (s[i]!=s[j]) return 0;
	return 1;
}

int check(char *s)
{
	int i;
	for (i=1;s[i]!='\0';i++)
		if (s[i]!=s[0]) return i;
	return 0;
}

int solve(char *s,int b)
{
	int i,c;
	if (s[0]=='\0') return 0;
	for (i=1;s[i]!='\0';i++)
		if (s[i]!=s[0]) break;
	if (i==b) return b;
	for (;i<b/2+1;i++)
		if (s[i]==s[0] && b%i==0) 
		{
			c=b/i/3;
			if (!c) c=i;
			else c*=i;
			if (judge(s,c,b))
				return b/i;
		}
	return 1;
}

main()
{
	char s[1000001];
	int b;
	while (cin.getline(s,1000001,'\n') && s[1]!='\0' || s[0]!='.')
	{
		b=strlen(s);
		cout<<solve(s,b)<<endl;
	}
	return 0;
}

