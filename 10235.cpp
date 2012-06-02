#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <cmath>

int reverse(int key)
{
	int temp=0;
	while (key/10)
	{
		temp+=key%10;
		temp*=10;
		key/=10;
	}
	temp+=key;
	return temp;
}

int prime(int key)
{
	int judge;
	int i;
	judge=sqrt(key);
	for (i=2;i<=judge;i++)
		if (key%i==0) return 0;
	return 1;
}

int emirp(int key)
{
	return prime(reverse(key));
}

main()
{
	int key;
	while (cin>>key)
	{
		if (prime(key) && emirp(key) && key!=reverse(key)) cout<<key<<" is emirp."<<endl;
		else if (prime(key)) cout<<key<<" is prime."<<endl;
		else cout<<key<<" is not prime."<<endl;
	}
	return 0;
}
