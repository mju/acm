#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void initial(int *p)
{
	int i;
	for (i=0;i<31;i++) p[i]=0;
}

void solve(char *s)
{
	int p[31];
	int i=0;
	int count=0;
	initial(p);
	while (1)
	{
		if (s[i]<='z' && s[i]>='a' || s[i]<='Z' && s[i]>='A')
			count++;
		else if (s[i]!='\'' && s[i]!='-') p[count]++,count=0;
		else if (s[i]=='\'' || s[i]=='-') 
			if (s[i+1]=='\n')
				i++;
		if (s[i]=='\0') break;
		i++;
	}
	for (i=1;i<31;i++)
		if (p[i]) cout<<i<<" "<<p[i]<<endl;
}

main()
{
	char s[100000];
	int judge=1;
	while (cin.getline(s,100000,'#'))
	{
		if (judge) judge=0;
		else cout<<endl;
		solve(s);
	}
	return 0;
}



	




















