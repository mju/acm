#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void initial(int *p)
{
	int i;
	for (i=0;i<800;i++)
		p[i]=0;
}

int process(int key)
{
	int p=0;
	while (key/10)
		p=p+(key%10)*(key%10),key/=10;
	p+=key*key;
	return p;
}

int happyNumber(int key)
{
	int p[800];
	initial(p);
	while (p[1]!=1)
	{
		if (p[key=process(key)]) return 0;
		else p[key]=1;
	}
	return 1;
}

main()
{
	int key;
	int N,i;
	cin>>N;
	for (i=1;i<=N;i++)
	{
		cin>>key;
		if (happyNumber(key)) cout<<"Case #"<<i<<": "<<key<<" is a Happy number."<<endl;
		else cout<<"Case #"<<i<<": "<<key<<" is an Unhappy number."<<endl;
	}
	return 0;
}

