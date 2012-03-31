#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int judge(const int &key)
{
	if (key<='z' && key>='a')
		if (key=='a' || key=='e' || key=='i' || key=='o' || key=='u')
			return 1;
	if (key<='Z' && key>='A')
		if (key=='A' || key=='E' || key=='I' || key=='O' || key=='U')
			return 1;
	return 0;
}

void solve(char *s)
{
	int i;
	char temp='\0';
	int check=1;
	for (i=0;s[i]!='\0';i++)
	{
		if (s[i]>='A' && s[i]<='Z' || s[i]>='a' && s[i]<='z')
		{
			if (check)
			{
				check=0;
				if (!judge(s[i])) temp=s[i];
				else cout<<s[i];
			}
			else cout<<s[i];
		}
		else
		{
			check++;
			if (check==1 && !judge(temp) && temp!='\0')
				cout<<temp<<"ay",temp='\0';
			else if (check==1) cout<<"ay";
			cout<<s[i];
		}
	}
	if (s[i-1]>='A' && s[i-1]<='Z' || s[i-1]>='a' && s[i-1]<='z')
	{
		if (!judge(temp) && temp!='\0')
			cout<<temp<<"ay",temp='\0';
		else cout<<"ay";
	}
	cout<<endl;
}

main()
{
	char s[1300000];
	while (cin.getline(s,1300000,'\n'))
		solve(s);
	return 0;
}

	