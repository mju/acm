#include <iostream>

using std::endl;
using std::cout;
using std::cin;

int s(int a,int b)//¶¶
{
	if (a>b)
		return a-b;
	else return a+40-b;
}

int l(int a,int b)
{
	if (a>b)
		return b+40-a;
	else return b-a;
}

main()
{
	int a,b,c,d;
	while (cin>>a>>b>>c>>d)
	{
		if (a==0 && b==0 && c==0 && d==0) break;
		cout<<s(a,b)*9+l(b,c)*9+s(c,d)*9+1080<<endl;
	}
	return 0;
}