#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int change(int key)
{
	int total=0;
	int test=1;
	while (key)
	{
		total+=key%10*test;
		key/=10;
		test*=16;
	}
	return total;
}

int count(int key)
{
	int test=2;
	int result;
	int times=0;
	while (key)
	{
		result=key%test;
		if (result)
			times++,key-=result;
		test*=2;
	}
	return times;
}

main()
{
	int N,i;
	int key;
	cin>>N;
	for (i=1;i<=N;i++)
		cin>>key,cout<<count(key)<<" "<<count(change(key))<<endl;
	return 0;
}
