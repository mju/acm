#include <iostream>

using std::endl;
using std::cout;
using std::cin;

struct build
{
	int left;
	int height;
	int right;
};

void swap(int &a,int &b)
{
	int stemp;
	stemp=a;
	a=b;
	b=stemp;
}

void bbsort(int n,int *p)
{
	int i,j;
	for (i=n-1;i>0;i--)
		for (j=1;j<=i;j++)
			if (p[j-1]>p[j])
				swap(p[j-1],p[j]);
}

int findHeight(int f,struct build *skyline,int key)
{
	int max=0;
	int i;
	for (i=0;i<f;i++)
		if ((skyline[i].left==key || skyline[i].right==key) && skyline[i].height>max)
			max=skyline[i].height;
	return max;
}

int judgeColumn(int &temp,int f,int k,struct build *skyline,int *column)
{
	int h;
	int i,j;
	int judge;
	for (i=temp;i<k;i++)
	{
		judge=0;
		if (column[i]==50000)
			continue;
		h=findHeight(f,skyline,column[i]);
		for (j=0;j<f;j++)
			if (skyline[j].left<column[i] && skyline[j].right>column[i] && skyline[j].height>=h)
			{
				judge=1;
				break;
			}
		if (judge==0) break;
	}
	if (judge==0 && i<k)
	{
		temp=i+1;
		return column[i];
	}
	else 
	{
		temp=k;
		return 60000;
  }
}

int judgeRow(int f,struct build *skyline,int C)
{
	int max=0;
	int i;
	for (i=0;i<f;i++)
		if (skyline[i].left<=C && skyline[i].right>C && skyline[i].height>max)
			max=skyline[i].height;
	return max;
}

main()
{
	struct build skyline[5000];
	int i,j;
	int *column;//¤W¤U
	//int *row;//¥ª¥k
	int f,k;
	int mtemp=0;
	int C;

	for (i=0;cin>>skyline[i].left>>skyline[i].height>>skyline[i].right;i++) ;

	column=new int[i*2];
	//row=new int[i];
	f=i;
	k=f*2;

	for (i=0;i<f;i++)
	{
		column[2*i]=skyline[i].left;
		column[2*i+1]=skyline[i].right;
		//row[i]=skyline[i].height;
	}

	bbsort(k,column);

	for (i=0;i<k;i++)
		for (j=0;j<k;j++)
			if (i!=j && column[i]==column[j])
				column[j]=50000;

	//for (i=0;i<k;i++)
	//	cout<<column[i]<<" ";
//	cout<<endl;
	int judge33=0;
	while (1)
	{
		C=judgeColumn(mtemp,f,k,skyline,column);
		if (mtemp==k && C==60000 && column[k-1]==50000)
		{
			cout<<endl;
			break;
		}
		if (judge33==0) judge33=1;
		else cout<<" ";
		cout<<C<<" ";
		if (mtemp==k)
		{
			cout<<"0"<<endl;
			break;
		}
		cout<<judgeRow(f,skyline,C);
	}
	return 0;
}




		
