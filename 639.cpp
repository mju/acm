#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int calculate(int key,int limit)
{
	int i;
    double f;
	f=(double)limit/3;
	i=1;
	while (key!=1)
	{
		if (key%2==0) key/=2,i++;
		else 
		{
			if (key>=f) return i;
			else key=key*3+1,i++;
		}
	}
	return i;
}

main()
{
	int A,L;
	int i=1;
	while (cin>>A>>L && A>=0 || L>=0)
		cout<<"Case "<<i<<": A = "<<A<<", limit = "<<L<<", number of terms = "<<calculate(A,L)<<endl,i++;
	return 0;
}
	
	
