#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void initial(int *p)
{
	int i;
	for (i=0;i<3000;i++) p[i]=0;
	p[0]=p[1]=1;
}

void solve(unsigned int *answer)
{
	int i,j;
	int p[3000];
	initial(p);
	answer[0]=1;
	for (i=1;i<1001;i++) answer[i]=0;
	for (i=2;i<=1001;i++)
	{
		for (j=1;j<3000;j++) answer[i-1]+=p[j];
		for (j=1;j<3000;j++) p[j]*=i;
		for (j=1;j<2999;j++) 
			if (p[j]>=10) p[j+1]+=p[j]/10,p[j]%=10;
	}
}

main()
{
	int key;
	unsigned int answer[1001];
	solve(answer);
	while (cin>>key)
		cout<<answer[key]<<endl;
	return 0;
}















