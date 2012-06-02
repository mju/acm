#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void add(int n,char *s,char *result)
{
	int carry=0;
	int temp;
	int i;
	for (i=n-1;i>=0;i--)
	{
		temp=s[i]-'0'+result[i]-'0'+carry;
		carry=temp/10,temp%=10;
		result[i]=temp+'0';
	}
}

main()
{
	int N;
	int i,j;
	int n;
	char *s,*result;
	cin>>N;
	for (j=1;j<=N;j++)
	{
		if (j!=1) cout<<endl;
		cin>>n;
		s=new char[n];
		result=new char[n];
		for (i=0;i<n;i++)
			cin>>s[i]>>result[i];
		add(n,s,result);
		for (i=0;i<n;i++) cout<<result[i];
		cout<<endl;
		delete [] s;
		delete [] result;
	}
	return 0;
}

















