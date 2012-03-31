#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void solve(int a,int b,int c,int d)
{
	double gogo=b,result=0.0;
	const double down=b*d/100.0;
	int i=1;
	while (1)
	{
		if (gogo>0) result+=gogo;
		if (result>a)
		{
			cout<<"success on day "<<i<<endl;
			return;
		}
		result-=c;
		if (result<0) 
		{
			cout<<"failure on day "<<i<<endl;
			return;
		}
		gogo-=down;
		i++;
	}
}

main()
{
	int a,b,c,d;
	while (cin>>a>>b>>c>>d && a)
		solve(a,b,c,d);
	return 0;
}


















