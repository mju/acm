#include <iostream>

using std::cout;
using std::cin;
using std::endl;

main()
{
	int n,*p,total;
	int average;
	int i,j=0;
	int judge=0;
	while (cin>>n && n!=0)
	{
		j++;
		total=average=0;
		p=new int[n];
		for (i=0;i<n;i++)
			cin>>p[i],average+=p[i];
		average/=n;
		for (i=0;i<n;i++)
			if (average-p[i]>0)
				total+=average-p[i];
		if (judge==0) cout<<"Set #"<<j<<endl<<"The minimum number of moves is "<<total<<"."<<endl,judge=1;
		else cout<<endl<<"Set #"<<j<<endl<<"The minimum number of moves is "<<total<<"."<<endl;	
	}
	cout<<endl;
	return 0;
}

