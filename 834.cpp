#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void solve(int a,int b)
{
	int c;
	int judge=1;
	cout<<"[";
	while (1)
	{
		cout<<a/b,c=b,b=a%b,a=c;
		if (!b) break;
		if (judge) cout<<";",judge=0;
		else cout<<",";
	}
	cout<<"]"<<endl;
}

main()
{
	int a,b;
	while (cin>>a>>b)
		solve(a,b);
	return 0;
}
	
	
