#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void handle(char *s)
{
	int i,j;
	int total=0;
	for (i=0;s[i]!='\0';i++)
	{
		if (s[i]<='9' && s[i]>='1')
		{
			total+=s[i]-'0';
		}
		else if (s[i]=='b') 
		{
			for (j=1;j<=total;j++)
				cout<<" ";
			total=0;
		}
		else if (s[i]=='!') cout<<endl;
		else 
		{
			for (j=1;j<=total;j++)
				cout<<s[i];
			total=0;
		}
	}
	cout<<endl;
}

main()
{
	char s[150];
	while (cin.getline(s,150,'\n'))
		handle(s);
	return 0;
}

