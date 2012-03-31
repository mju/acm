#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;

#include <cstdlib>

class bigNumber
{
	friend ostream &operator<<(ostream &,const bigNumber &);
	friend istream &operator>>(istream &,bigNumber &);
private :
	char body[1000];
	int count(void);
public :
	void operator+(bigNumber &);
	void operator*(bigNumber &);
};

ostream &operator<<(ostream &output,const bigNumber &right)
{
	output<<right.body;
	return output;
}

istream &operator>>(istream &input,bigNumber &right)
{
	input>>right.body;
	return input;
}

int bigNumber::count(void)
{
	int i;
	for (i=0;body[i]!='\0';i++) ;
	return i-1;
}

void bigNumber::operator+(bigNumber &right)
{
	int i,j,t=0;
	int k;
	int asdf;
	int jj;
	char *temp;
	i=count();
	j=right.count();
	if (i>j) temp=new char[i+2],k=i;
	else temp=new char[j+2],k=j;
	temp[k+1]='\0';
	while (i>-1 || j>-1)
	{
		if (i<0) asdf=0,jj=right.body[j]-'0';
		else if (j<0) jj=0,asdf=body[i]-'0';
		else asdf=body[i]-'0',jj=right.body[j]-'0';
		t=t+asdf+jj;
		temp[k]=t%10+'0';
		t/=10;
		i--,j--,k--;
	}
	if (t!=0)
	{
		body[0]=t+'0';
		strcpy(body+1,temp);
	}
	else strcpy(body,temp);
}

void bigNumber::operator*(bigNumber &right)
{
	bigNumber temp;
	temp.body[0]='0';
	temp.body[1]='\0';
	bigNumber tempt;
	char *t;
	int i,j,k,p,kk;
	int jjj;
	int judge;
	i=count();
	j=right.count();
	t=new char[i+2];
	kk=j;
	while (kk>-1)
	{
		p=0;
		t[i+1]='\0';
		for (k=i;k>-1;k--)
		{
			jjj=(right.body[kk]-'0')*(body[k]-'0')+p;
			t[k]=jjj%10+'0';
			p=jjj/10;
		}
		if (p==0) 
		{
			strcpy(tempt.body,t);
			judge=i+1;
		}
		else 
		{
			tempt.body[0]=p+'0';
			strcpy(tempt.body+1,t);
			judge=i+2;
		}
		for (k=0;k<j-kk;k++)
			tempt.body[judge]='0',tempt.body[judge+1]='\0',judge++;
		if (tempt.body[0]!='0')
			temp+tempt;
		kk--;
	}
	strcpy(body,temp.body);
}

main()
{
	bigNumber a,b;
	while (cin>>a>>b)
	{
		a*b;
		cout<<a<<endl;
	}
	return 0;
}

		







	


		










			
			

