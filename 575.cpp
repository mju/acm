#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int count(char *s)
{
	int i;
	for (i=0;s[i]!='\0';i++);
	return i;
}

unsigned int calculate(char *s)
{
	unsigned int multiply=2;
	unsigned int summation=0;
	int i;
	for (i=count(s)-1;i>=0;i--,multiply*=2)
		summation+=(s[i]-'0')*(multiply-1);
	return summation;
}

main()
{
	char s[1000];
	while (cin>>s && s[0]!='0')
		cout<<calculate(s)<<endl;
	return 0;
}
