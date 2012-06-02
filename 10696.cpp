#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int calculate(const int &key)
{
	if (key>100) return key-10;
	return 91;
}

main()
{
	int key;
	while (cin>>key && key)	cout<<"f91("<<key<<") = "<<calculate(key)<<endl;
	return 0;
}





 