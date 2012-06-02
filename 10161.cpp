#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <cmath>

int absolute(const int &key)
{
	return key>=0?key:-key;
}

void bye(const int &key)
{
	int temp;
	int axi;
	int distance;
	temp=sqrt(key);
	if (temp*temp==key)
	{
		if (key%2) cout<<"1 "<<temp<<endl;
		else cout<<temp<<" 1"<<endl;
		return;
	}
	else temp++;
	axi=temp*temp-temp+1;
	distance=absolute(axi-key);
	if (temp%2 && key<axi || temp%2==0 && key>axi) cout<<temp<<" "<<temp-distance<<endl;
	else cout<<temp-distance<<" "<<temp<<endl;
}

main()
{
	int key;
	while (cin>>key && key)	bye(key);
	return 0;
}
		
		





