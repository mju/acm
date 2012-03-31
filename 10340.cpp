#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int judge(char *a,char *b)
{
	int ap,bp=0;
	int judge;
	for (ap=0;a[ap]!='\0';ap++)
	{
		judge=0;
		while (b[bp]!='\0')
		{
			if (b[bp]==a[ap])
			{
				judge=1;
				bp++;
				break;
			}
			bp++;
		}
		if (judge==0) return 0;
	}
    return 1;
}

main()
{
	char a[100000],b[100000];
	while (cin>>a>>b)
	{
		if (judge(a,b)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}

