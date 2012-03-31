#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int findOut(int *p,char **S_Array,int n,char *key)
{
	int i;
	for (i=0;i<n;i++)
		if (!strcmp(S_Array[i],key))
			return p[i];
	return 0;
}

main()
{
	int n,m;
	int i;
	char *S_Array[1000];
	int p[1000];
	char key[20];
	int total;
	cin>>n>>m;
	for (i=0;i<n;i++)
	{
		S_Array[i]=new char[20];
		cin>>S_Array[i]>>p[i];
	}
	for(i=1;i<=m;i++)
	{
		total=0;
		key[0]='a';
		while (key[0]!='.' || key[1]!='\0')
		{
			cin>>key;
			total+=findOut(p,S_Array,n,key);
		}
		cout<<total<<endl;
	}
	return 0;
}


