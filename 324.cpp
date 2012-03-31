#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <iomanip>

using std::setw;

void byebye(int key)
{
	int i,j;
	int p[800];
	int q[10];
	for (i=0;i<800;i++) p[i]=0;
	p[799]=1;
	for (i=0;i<10;i++) q[i]=0;
	for (i=2;i<=key;i++)
	{
		for (j=799;j>=0;j--) p[j]*=i;
		for (j=799;j>0;j--) 
			if (p[j]>10) p[j-1]+=p[j]/10,p[j]%=10;
	}
	for (i=0;i<800;i++) 
		if (p[i]!=0) break;
	for (;i<800;i++) q[p[i]]++;
	cout<<key<<"! --"<<endl<<"   ";
	for (i=0;i<10;i++)
	{
		cout<<"("<<i<<")"<<setw(5)<<q[i]<<"    ";
		if (i==4) cout<<endl<<"   ";
		else if (i==9) cout<<endl;
	}
}

main()
{
	int key;
	while (cin>>key && key)
		byebye(key);
	return 0;
}












