#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void solve(char *s)
{
	int i,j;
	char *table="`1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./\\\"";
	for (i=0;s[i]!='\0';i++)
	{
		if (s[i]>='A' && s[i]<='Z') s[i]=s[i]-'A'+'a';
		if (s[i]==' ')
		{
			cout<<" ";
			continue;
		}
		for (j=0;table[j]!='\0';j++)
			if (s[i]==table[j])
			{
				cout<<table[j-2];
				break;
			}
	}
	cout<<endl;
}

main()
{
	char s[1000];
	cin.getline(s,1000,'\n');
	solve(s);
	return 0;
}