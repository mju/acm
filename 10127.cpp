#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int count(int key)
{
	int i;
	int digit=0;
	int t;
	int key1=key;
	while (1)
	{
		if (key1%10==1) key1/=10,digit++;
		else 
		{
			t=11-(key1%10);
			if (t==11) t=1;
			for (i=1;i<10;i++)
				if ((key*i)%10==t) break;
			key1+=key*i;
		}
		if (key1==0) break;
	}
	return digit;
}

main()
{
	int key;
	while (cin>>key)
		cout<<count(key)<<endl;
	return 0;
}



