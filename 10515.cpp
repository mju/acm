#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int count(char *key)
{
	int i;
	if (key[1]=='\0') return key[0]-'0';
	for (i=2;key[i]!='\0';i++) ;
	return (key[i-2]-'0')*10+(key[i-1]-'0')+100;
}

int answer(int key,int times)
{
	int a,b;
	int i;
	a=key%10;
	if (key==0) return 0;
	if (times==0) return 1;
	times=times%4;
	if (times==0) times=4;
	b=1;
	for (i=1;i<=times;i++)
		b*=a,b%=10;
	return b;
}

main()
{
	char key[1020];
	char times[1020];
	while (cin>>key>>times)
	{
		if (key[0]=='0' && times[0]=='0') break;
		cout<<answer(count(key),count(times))<<endl;
	}
	return 0;
}
