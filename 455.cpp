#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <cstdlib>

int judge(char *s,int length)
{
	int i;
	int j;
	for (i=length,j=0;s[i]!='\0';i++,j++)
		if (s[i]!=s[j]) return 0;
	return i;
}

int solve(char *s,int b)
{
	int i;
	int length;
	if (s[0]=='\0') return 0;
	for (i=1;s[i]!='\0';i++)
		if (s[i]==s[0] && b%i==0) 
			if (length=judge(s,i))
				return i;
	return b;
}

main()
{
	char s[100001];
	int N,b;
	int i;
	cin>>N;
	for (i=1;i<=N;i++)
	{
		cin>>s;
		b=strlen(s);
		cout<<solve(s,b)<<endl<<endl;
	}
	return 0;
}

