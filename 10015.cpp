#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <cmath>

bool prime(int key)
{
	int a;
	a=sqrt(key)+1;
	if (key==1)
		return 0;
	for (int i=2;i<a;i++)
		if (key%i==0)
			return 0;
	return 1;
}

main()
{
	int n;
	int position;
	int *p;
	int i;
	int j;
	int key;
	int k;
	int y;

	while (1)
	{
		y=0;
		position;
		key=2;
		cin>>n;
		if (n==0) break;
		p=new int[n];
		for (i=0;i<n;i++)
			p[i]=1;
		for (i=1;i<n;i++)
		{
			while (1)
			{
				if (prime(key))
					break;
				key++;
			}
			j=0;
			//cout<<key<<endl;
			while (j<key)
			{
				//cout<<j;
				if (p[y]!=0)
				{	
					j++;
					position=y;
				}
				y++;
				if (y>n-1) y=0;
			}
			p[position]=0;
			key++;
		}
		for (i=0;i<n;i++)
			if (p[i]!=0)
			{
				cout<<i+1<<endl;
				break;
			}
	}
	return 0;
}




			


			



