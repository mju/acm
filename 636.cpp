#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <cmath>

int calculate(int key,int base)
{
	int multiply=1;
	int answer=0;
	while (key)
	{
		if (key%10>=base) return 0;
		answer+=key%10*multiply;
		key/=10;
		multiply*=base;
	}
	return answer;
}

int solve(int key)
{
	int i;
	int qrt;
	for (i=2;i<=100;i++)
	{
		qrt=sqrt(calculate(key,i));
		if (!qrt) continue;
		if (qrt*qrt==calculate(key,i)) break;
	}
	return i;
}

main()
{
	int key;
	while (cin>>key && key)
		cout<<solve(key)<<endl;
	return 0;
}

