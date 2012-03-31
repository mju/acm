#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void swap(int &a,int &b)
{
	int c;
	c=a;
	a=b;
	b=c;
}

void bbsort(int *p,int n)
{
	int i,j;
	for (i=n-1;i>0;i--)
		for (j=1;j<=i;j++)
			if (p[j-1]<p[j])
				swap(p[j-1],p[j]);
}

int sum(int *p,int n)
{
	int i;
	int summation=0;
	for (i=0;i<n;i++)
		summation+=p[i];
	return summation;
}

bool judge(int *p,int n,int length)
{
	int i;
	for (i=0;i<n;i++)
		if (p[i]>length) return 1;
	return 0;
}

void initial(int *q,int n)
{
	int i;
	for (i=0;i<n;i++) q[i]=0;
}

char *solve(int *p,int n)
{
	int length;
	int total=1;
	int position[3]={0,0,0};
	int *q;
	int pointer=0;
	int i,j;
	int temp;
	int summation;
	if (sum(p,n)%4) return "no";
	length=sum(p,n)/4;
	if (judge(p,n,length)) return "no";
	bbsort(p,n);
	q=new int[n];
	initial(q,n);
	for (i=0;i<n;i++)
		if (p[i]==length) q[i]=total,position[pointer]++,total++;
	if (p[position[pointer]]+p[n-1]>length) return "no";
	summation=0;
	summation+=p[position[pointer]];
	q[position[pointer]]=total;
	temp=position[pointer];	
	i=position[pointer]+1;
	while (total<4)
	{
		
		for (;i<n;i++)
		{
			if (q[i]==0 && p[i]<=length-summation) q[i]=total,summation+=p[i],temp=i;
			if (summation==length)
			{
				summation=0;
				for (j=0;j<n;j++)
					if (q[j]==0)
					{
						position[++pointer]=j;
						q[j]=++total;
						break;
					}
				summation+=p[j];
				for (j=position[pointer]+1;j<n;j++)
					if (q[j]==0)
					{
						i=temp=j;
						break;
					}
				break;
			}
		}
		if (i>=n) 
		{
			if (pointer==0)	return "no";
			if (temp==position[pointer]) 
			{
				q[position[pointer]]=0;
				pointer--;
				total--;
				summation=length;
				for (j=n-1;j>=0;j--)
					if (q[j]==total)
					{
						q[j]=0;
						summation-=p[j];
						break;
					}
				for (;j>=0;j--)
					if (q[j]==total)
					{
						q[j]=0;
						temp=j;
						i=j;
						summation-=p[j];
						break;
					}
			}
			else 
			{
				q[temp]=0;
				for (j=temp+1;j<n;j++)
					if (q[j]==0)
					{
						summation-=p[temp];
						i=j;
						temp=j;
						break;
					}
			}
		}
	}
	return "yes";
}

main()
{
	int *p;
	int n;
	int N;
	int i;
	cin>>N;
	while (N>0)
	{
		cin>>n;
		p=new int[n];
		for (i=0;i<n;i++) cin>>p[i];
		cout<<solve(p,n)<<endl;
		delete [] p;
		N--;
	}
	return 0;
}










		






