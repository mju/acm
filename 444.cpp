#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <cstdlib>

int reverse(int key)
{
	int temp=0;
	while (key)
	{
		temp*=10;
		temp+=key%10;
		key/=10;
	}
	return temp;
}

int check(char *p)
{
	int i;
	for (i=0;p[i]!='\0';i++)
		if (p[i]!=' ')
		{
			if (p[i]<'0' || p[i]>'9') return -1;
			else return i;
		}
}

main()
{
	char s[99999];
	int i,j,temp;
	while (cin.getline(s+1,9999,'\n'))
	{
		s[0]='a';
		if (s[1]=='\0') 
		{
			cout<<endl;
			continue;
		}
		if (check(s+1)==-1)
		{
			for (i=0;s[i]!='\0';i++) ;
			for (i--;i>=1;i--)
				if (reverse((int)s[i])==1) cout<<"001";
				else if (reverse((int)s[i])==11) cout<<"011";
				else if (reverse((int)s[i])==21) cout<<"021";
				else if (reverse((int)s[i])==7) cout<<"07";
				else if (reverse((int)s[i])==8) cout<<"08";
				else if (reverse((int)s[i])==9) cout<<"09";
				else if (reverse((int)s[i])!=1) cout<<reverse((int)s[i]);
			cout<<endl;
		}
		else
		{
			for (i=0;s[i]!='\0';i++) ;
			for (i--;i>check(s+1);)
			{
				temp=0;
				if (s[i]-'0'==1)
				{
					for (j=0;j<3;j++)
					{
						temp*=10;
						temp+=s[i-j]-'0';
					}
					i-=3;
					cout<<(char)temp;
				}
				else
				{
					for (j=0;j<2;j++)
					{
						temp*=10;
						temp+=s[i-j]-'0';
					}
					i-=2;
					cout<<(char)temp;
				}
			}
			cout<<endl;
		}
	}
	return 0;
}
