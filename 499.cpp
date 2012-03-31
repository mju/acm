#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void initial(int *p)
{
	int i;
	for (i=0;i<130;i++)
		p[i]=0;
}

int process(char *s,int *p)
{
	int i;
	int max=0;
	initial(p);
	for (i=0;s[i]!='\0';i++)
	{
		if ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))
		{
			p[s[i]]++;
			if (p[s[i]]>max) max=p[s[i]];
		}
	}
	return max;
}

main()
{
	char s[2000];
	int p[130];
	int i,max;
	while (cin.getline(s,2000,'\n'))
	{
		max=process(s,p);
		for (i=0;i<130;i++)
			if ((i>='A' && i<='Z') || (i>='a' && i<='z'))
				if (p[i]==max) cout<<(char)i;
		cout<<" "<<max<<endl;
	}	
	return 0;
}




