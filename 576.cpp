#include <iostream>

using std::cout;
using std::cin;
using std::endl;

bool judge(const char &key)
{
	return key=='a' || key =='e' || key=='i' || key=='o' || key=='u' || key=='y';
}

bool solve(char *s)
{
	int i=0;
	int yes=1;
	int times=1;
	int count=0;
	int p[4]={0,5,7,5};
	if (s[0]=='e' && s[1]=='/' && s[2]=='o' && s[3]=='/' && s[4]=='i' && s[5]=='\0') return 0;
	while (1)
	{
		if (s[i]=='/' || s[i]=='\0') 
		{
			if (count!=p[times])
			{
				cout<<times<<endl;
				return 1;
			}
			if (s[i]=='\0')
			{
				cout<<"Y"<<endl;
				return 1;
			}
			times++;
			count=0;
		}
		if (judge(s[i]) && yes) 
		{
			yes=0;
			count++;
		}
		else if (!judge(s[i])) yes=1;
		i++;
	}
}

main()
{
	char s[2000];
	while (cin.getline(s,2000,'\n') && solve(s)) ;
	return 0;
}


