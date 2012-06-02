#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <cmath>

bool process(const unsigned int &key)
{
	int i=sqrt(key);
	if (i*i==key) return 1;
	return 0;
}

main()
{
	unsigned int key;
	while (cin>>key && key)
		if (process(key)) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	return 0;
}




















