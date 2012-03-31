#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int calculate(int a,int b,int c)
{
	int n=b,i=1;
	while (n/c!=b || n%c!=0)
		n=n%c*a+n/c,i++;
	return i;
}

main()
{
	int a,b,c;
	while (cin>>a>>b>>c)
		cout<<calculate(a,b,c)<<endl;
	return 0;
}

/*
  本題是用除法來算的
  如果xyz乘以某數後會變為
  zxy那zxy/某數就是xyz*/
	

	
		

