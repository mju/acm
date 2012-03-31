#include <iostream>

using std::cout;
using std::cin;
using std::endl;

unsigned int calculate(unsigned long up,unsigned long down)
{
	unsigned int twos=1,answer=0;
	while (up || down)
	{
		twos*=2;
		if (up%twos && down%twos) up-=twos/2,down-=twos/2;
		else if (up%twos) up-=twos/2,answer+=twos/2;
		else if (down%twos) down-=twos/2,answer+=twos/2;
	}
	return answer;
}

main()
{
	unsigned int a,b;
	while (cin>>a>>b)
		cout<<calculate(a,b)<<endl;
	return 0;
}



 