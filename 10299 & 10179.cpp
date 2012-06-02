#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <cmath>

int solve(int key)
{
	if (key==1) return 1;
	int i;
	int temp=key;
	key--;
	if (temp%2==0) key-=key/2;
	while (temp%2==0)
		temp/=2;
	for (i=3;i<=sqrt(temp);i+=2)
	{
		if (temp%i==0)
		{
			key-=key/i;
			while (temp%i==0)
				temp/=i;
		}
	}
	if (temp!=1) key-=key/temp;
	return key;
}

main()
{
	int key;
	while (cin>>key && key)
		cout<<solve(key)<<endl;
	return 0;
}
	
	
			
			






 