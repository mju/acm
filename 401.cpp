#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const char a[35]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','R','S','T','U','V','W','X','Y','Z','1','2','3','4','5','6','7','8','9'};
const char b[35]={'A',' ',' ',' ','3',' ',' ','H','I','L',' ','J','M',' ','O','P','R','2','T','U','V','W','X','Y','5','1','S','E',' ','Z',' ',' ','8',' '};

int process(char *p)
{
	int i;
	for (i=0;p[i]!='\0';i++)
		if (p[i]=='0') p[i]='O';
	return i;
}

int palindrome(char *p)
{
	int length;
	int times;
	int i;
	length=process(p);
	if (length==1) return 1;
	times=length/2;
	length--;
	for (i=0;i<times;i++,length--)
		if (p[i]!=p[length]) return 0;
	return 1;
}

int mirrored(char *p)
{
	int length;
	int times;
	int i,j;
	length=process(p);
	if (length==1) 
	{
		for (i=0;i<35;i++)
			if (p[0]==a[i]) break;
		if (a[i]==b[i]) return 1;
		else return 0;
	}
	if (length%2)
	{
		for (i=0;i<35;i++)
			if (p[length/2]==a[i]) break;
		if (a[i]!=b[i]) return 0;
	}
	times=length/2;
	length--;
	for (i=0;i<times;i++,length--)
	{
		for (j=0;j<35;j++)
			if (a[j]==p[i]) break;
		if (p[length]!=b[j]) return 0;
	}
	return 1;
}

main()
{
	char p[10000];
	int mr,pd;
	while (cin>>p)
	{
		mr=mirrored(p);
		pd=palindrome(p);
		if (mr==0 && pd==1) cout<<p<<" -- is a regular palindrome."<<endl;
		else if (mr==0 && pd==0) cout<<p<<" -- is not a palindrome."<<endl;
		else if (mr==1 && pd==0) cout<<p<<" -- is a mirrored string."<<endl;
		else if (mr==1 && pd==1) cout<<p<<" -- is a mirrored palindrome."<<endl;
		cout<<endl;
	}
	return 0;
}




