#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void initial(bool *p)
{
	int i;
	for (i=0;i<1001;i++)
		p[i]=1;
	p[0]=p[1]=0;
}

int summation(int key)
{
	int total=0;
	while (key)
		total+=key%10,key/=10;
	return total;
}

main()
{
	bool prime[1001];
	int record[1000001];
	int i,j;
	int howmany;
	int n;
	int k;
	int temp=0;
	int judge;
	int first;
	int t1,t2;
	record[0]=0;
	initial(prime);
	for (i=2;i<1001;i++)
		for (j=i+1;j<1001;j++)
			if (prime[j] && j%i==0) prime[j]=0;
	cin>>n;
	howmany=0;
	first=1;
	for (i=1;i<=1000000;)
	{
		if (temp==10) temp=0,first=summation(i);
		if (i<1000 && prime[first])
		{
			if (prime[i]) howmany++,record[i]=howmany;
		}
		else if (i>1000)
		{
			if (prime[first])
			{
				judge=1;
				for (j=2;j<1000;)
				{
					if (i%j==0)
					{
						judge=0;
						break;
					}
					if (j%2)
					{
						j+=2;
						if (j%5==0 && j>9) j+=2;
					}
					else j++;
				}
				if (judge && prime[first]) howmany++,record[i]=howmany;
			}
		}
		if (i%2 && i!=1)
		{
			i+=2,temp+=2,first+=2;
			record[i-2]=howmany;
			record[i-1]=howmany;
			if (i%5==0 && i>9) i+=2,temp+=2,first+=2,record[i-2]=record[i-1]=howmany;
		}
		else i++,temp++,first++,record[i]=howmany;
	}
	for (k=1;k<=n;k++)
		cin>>t1>>t2,cout<<record[t2]-record[t1-1]<<endl;
	return 0;
}				
	

