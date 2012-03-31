#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void initial(int *p,int n)
{
	int i;
	for (i=0;i<n;i++)
		p[i]=i;
}

main()
{
	int fuckyou=1;
	int person;
	int finalPerson;
	int poke;
	int *p,temp;
	int i,j,k;
	int judge;
	int jj=1;
	while (cin>>person>>finalPerson)
	{
		p=new int[person];
		initial(p,person);
		temp=person;
		judge=0;
		for (i=0;i<20;i++)
		{
			cin>>poke;
			if (temp!=finalPerson)
			{
				for (j=0,k=1;j<person;j++)
				{
					if (p[j]!=-1)
					{
						if (k%poke==0) 
						{
							temp--;
							p[j]=-1;
							if (temp==finalPerson)
							{
								judge=1;
								break;
							}
						}
						k++;
					}
					if (judge) break;
				}
			}
		}
	//	if (fuckyou) fuckyou=0;
	//	else cout<<endl;
		cout<<"Selection #"<<jj<<endl;
		judge=1;
		for (i=0;i<person;i++)
			if (p[i]!=-1)
			{
				if (judge) cout<<p[i]+1,judge=0;
				else cout<<" "<<p[i]+1;
			}
		cout<<endl<<endl;
		jj++;
	}
	return 0;
}


			
			

