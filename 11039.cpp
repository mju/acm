#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#define	SIZE	1000000

void initial(int *a)
{
	int i;

	for (i=0;i<SIZE;i++)
		a[i]=0;
}

main()
{
	int C,T;
	int i;
	int height;
	int key;
	int judge;

	int theArray[SIZE];

	for (cin>>C;C>0;C--)
	{
		height=0;

		initial(theArray);

		for (cin>>T;T>0;T--)
		{
			cin>>key;

			if (key>0) theArray[key]=1;
			else if (key<0) theArray[0-key]=-1;
		}

		for (i=0,judge=0;i<SIZE;i++)
			if (theArray[i]!=0 && judge!=theArray[i])
				judge=theArray[i],height++;

		cout<<height<<endl;
	}

	return 0;
}