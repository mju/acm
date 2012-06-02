#include <iostream>

using std::cout;
using std::cin;
using std::endl;

main()
{
	char a[10000];
	int i,j;
	while (cin.getline(a,9999,'\n'))
	{
		for (i=0;a[i]!='\0';i++)
		{
			if (a[i]==' ')
			{
				for (j=i-1;j!=-1 && a[j]!=' ';j--)
					cout<<a[j];
				cout<<" ";
			}
			else if (a[i+1]=='\0')
			{
				for (j=i;a[j]!=' ' && j!=-1;j--)
					cout<<a[j];
				cout<<endl;
			}
		}
	}
	return 0;
}



