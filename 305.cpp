#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int answers[14]={0,2,0,0,0,0,0,0,0,0,0,0,0,0};

void initial(int *p,int n)
{
	int i;
	for (i=0;i<n;i++) 
		p[i]=0;
}

int Joseph(int key)
{
	if (answers[key]) return answers[key];
	int i;
	int *p;
	int j;
	int k;
	int temp;
	int times;
	int elements;
	p=new int[2*key+1];
	j=key-1;
	while (times!=key)
	{
		times=0;
		elements=2*key;
		initial(p,2*key+1);
		temp=j%elements;
		if (!temp) temp=elements;
		i=k=temp;
		while (times!=key)
		{
			if (k==temp) 
			{	
				k=0;
				p[i]=1,elements--,temp=j%elements;
				if (!temp) temp=elements;
				if (i>key) times++;
				else break;
			}
			if (i==key*2) i=0;
			i++;
			if (!p[i]) k++;		
		}
		j++;
	}
	j--;
	answers[key]=j;
	return j;
}

main()
{
	int k;
	while (cin>>k && k)
		cout<<Joseph(k)<<endl;
	return 0;
}


			
	


 