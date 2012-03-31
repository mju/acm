#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void initial(char **s,int *p,int *q,int n)
{
	int i;
	for (i=0;i<n;i++)
		p[i]=1,q[i]=i,s[i][0]=i+'0',s[i][1]='\0';		
}

void Put(int key,int position,int target,char **s,int *p,int *q)
{
	s[target][p[target]+1]='\0';
	s[target][p[target]++]=s[key][position];
	p[key]--;
	q[s[key][position]-'0']=target;
	s[key][position]='\0';
}

void PutBack(int key,int position,char **s,int *p,int *q)
{
	int i;
	for (i=p[key]-1;i>position;i--)
		Put(key,i,s[key][i]-'0',s,p,q);
}

void MoveOnto(int a,int b,char **s,int *p,int *q)
{
	int position;//歸回動作用的
	int i;
	for (i=0;s[q[a]][i]!=a+'0';i++);
	position=i;
	PutBack(q[a],i,s,p,q);
	for (i=0;s[q[b]][i]!=b+'0';i++);
	PutBack(q[b],i,s,p,q);
	Put(q[a],position,q[b],s,p,q);
}

void MoveOver(int a,int b,char **s,int *p,int *q)
{
	int i;
	for (i=0;s[q[a]][i]!=a+'0';i++);
	PutBack(q[a],i,s,p,q);
	Put(q[a],i,q[b],s,p,q);
}

void PileOnto(int a,int b,char **s,int *p,int *q)
{
	int position3;
	int position2;
	int position;
	int i;
	for (i=0;s[q[b]][i]!=b+'0';i++);
	PutBack(q[b],i,s,p,q);
	position=i;
	for (i=0;s[q[a]][i]!=a+'0';i++);
	position++;
	position2=i;
	position3=q[a];
	while (s[position3][i]!='\0')
	{
		s[q[b]][position]=s[position3][i];
		q[s[position3][i]-'0']=q[b];
		i++,position++;
	}
	p[position3]=position2;
	p[q[b]]=position;
	s[position3][position2]='\0';
	s[q[b]][position]='\0';
}

void PileOver(int a,int b,char **s,int *p,int *q)
{
	int position3;
	int position,position2,i;
	position=p[q[b]];
	for (i=0;s[q[a]][i]!=a+'0';i++);
	position2=i;
	position3=q[a];
	while (s[position3][i]!='\0')
	{
		s[q[b]][position]=s[position3][i];
		q[s[position3][i]-'0']=q[b];
		i++,position++;
	}
	p[position3]=position2;
	p[q[b]]=position;
	s[position3][position2]='\0';
	s[q[b]][position]='\0';
}

main()
{
	int j;
	char **s;
	int *p;
	int *q;
	int n;
	char one[5],two[5];
	int a,b;
	int i;
	while (cin>>n)
	{
		s=new char*[n];
		p=new int[n];
		q=new int[n];
		for (i=0;i<n;i++)
			s[i]=new char[n+1];
		initial(s,p,q,n);
		while (cin>>one && strcmp(one,"quit")!=0)
		{
			cin>>a>>two>>b;
			if (a==b || q[a]==q[b] || a>n || b>n || a<0 || b<0) continue;
			if (strcmp(one,"move")==0)
			{
				if (strcmp(two,"onto")==0)
					MoveOnto(a,b,s,p,q);
				else MoveOver(a,b,s,p,q);
			}
			else
			{
				if (strcmp(two,"onto")==0) 
					PileOnto(a,b,s,p,q);
				else PileOver(a,b,s,p,q);
			}
		}
		for (i=0;i<n;i++) 
		{
			cout<<i<<":";
			for (j=0;s[i][j]!='\0';j++) cout<<" "<<(int)s[i][j]-'0';
			cout<<endl;
		}
		//
		//for (i=0;i<n;i++) cout<<q[i]<<" ";
		//cout<<endl;
		//for (i=0;i<n;i++) cout<<p[i]<<" ";
		//cout<<endl;
	}
	return 0;
}
			


	
