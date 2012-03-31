#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct company
{
	int condition;
	double prise;
	char name[100];
};

char *process(company *a,int n)
{
	int max=-1;
	double min=9999999999.99999;
	char *answer;
	int i;
	for (i=0;i<n;i++)
		if (a[i].condition>max) max=a[i].condition;
	for (i=0;i<n;i++)
		if (a[i].condition==max && a[i].prise<min) min=a[i].prise,answer=a[i].name;
	return answer;
}

main()
{
	int n,p;
	int i,j,k=0,judge=0;
	char request[100];
	company *a;
	while (cin>>n>>p && n || p)
	{
		k++;
		for (i=0;i<n+1;i++) cin.getline(request,100,'\n');
		a=new company[p];
		for (i=0;i<p;i++)
		{
			cin.getline(a[i].name,100,'\n');
			cin>>a[i].prise>>a[i].condition;
			if (a[i].condition==0) continue;
			for (j=0;j<a[i].condition+1;j++) cin.getline(request,100,'\n');
		}
		if (judge==0) judge=1;
		else cout<<endl;
		cout<<"RFP #"<<k<<endl<<process(a,p)<<endl;
		delete a;
	}
	return 0;
}



			
			

