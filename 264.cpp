#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void solve(int key)
{
	int i=1,a,b=1,c;
	while ((1+i)*i/2<key)
		i++;
	a=i;
	if (i%2) c=i-((1+i)*i/2)+key-1;
	else c=((1+i)*i/2)-key;
	for (i=1;i<=c;i++)
		a--,b++;
	cout<<"TERM "<<key<<" IS "<<a<<"/"<<b<<endl;
}

main()
{
	int key;
	while (cin>>key)
		solve(key);
	return 0;
}
