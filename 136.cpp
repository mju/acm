#include <iostream>

using std::cout;
using std::cin;
using std::endl;

main()
{
	int a[7]={30,15,10,6,5,3,2};
	int count=1;
	int j;
	//int position;
	int judge;
	int k;
	for (int i=2;count<1500;i++)
	{
		//cout<<i<<" ";
		k=i;
		judge=0;
	//	position=0;
		while (k>5)
		{
			for (j=0;j<7;j++)
			{
				if (i==7) cout<<j<<" ";
				if (k%a[j]==0)
				{
					judge=0;
					k=k/a[j];
					if (k<=5)
						break;
					else
					{
						if (j==6)
							j=0;
					}
				}
				else judge=1;
			}
			if (judge!=0)
				break;
		}
		if (k<=5)
		{
			cout<<i<<" ";
			count++;
			cout<<count<<" ";
		}
		else continue;
	}
	//cout<<"The 1500'th ugly number is "<<i<<"."<<endl;
	return 0;
}




		

