#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int process(char *s,int *p)
{
	int i=0;
	int max=0;
	int total=0;
	int j=0;
	while (1)
	{
		if (s[i]<='9' && s[i]>='0')
			total*=10,total+=s[i]-'0';
		if (s[i]==' ' || s[i]=='\0')
		{
			p[j]=total,j++;
			if (total>max) max=total;
			total=0;;
			if (s[i]=='\0') break;
		}
		i++;
	}
	return max;
}

main()
{
	int p[1000000],j;
	int i,kk;
	int N,k;
	char s[1000000];
	char q[1000000];
	int max;
	int times;
	int judge=1,kkk;
	int test;
	cin>>N;
	cin.getline(s,1000000,'\n');
	for (k=1;k<=N;k++)
	{
		if (judge) judge=0;
		else cout<<endl;
		cin.getline(s,1000000,'\n');
		cin.getline(s,1000000,'\n');
		cin.getline(q+1,1000000,'\n');
		max=process(s,p);
		q[0]=' ';
		//cout<<s<<endl<<q<<endl;
		//for (i=0;i<max;i++) cout<<p[i]<<" ";
		//cout<<endl;
		//cout<<max<<endl;
		for (i=1;i<=max;i++)
		{
			test=0;
			for (j=0;j<max;j++)
				if (p[j]==i)
				{
					times=-1;
					for (kk=0;q[kk]!='\0';kk++)
						if (q[kk]==' ') 
						{
							times++;
							if (times==j) 
							{
								for (kkk=kk+1;q[kkk]!=' ' && q[kkk]!='\0';kkk++)
									cout<<q[kkk];
								cout<<endl;
								test=1;
								break;
							}
						}
						if (test) break;
				}
		}
	}
	return 0;
}





