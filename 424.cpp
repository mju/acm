#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;

class VeryLongInteger
{
	friend ostream &operator<<(ostream &,const VeryLongInteger &);
private :
	char okok[150];
	int count(const char *s);
public :
	VeryLongInteger(void);
	void operator+(const char *s);
};

ostream &operator<<(ostream &output,const VeryLongInteger &right)
{
	int i;
	for (i=0;right.okok[i]=='0';i++);
	output<<right.okok+i;
	return output;
}

VeryLongInteger::VeryLongInteger(void)
{
	int i;
	for (i=0;i<149;i++) okok[i]='0';
	okok[149]='\0';
}

int VeryLongInteger::count(const char *s)
{
	int i;
	for (i=0;s[i]!='\0';i++) ;
	return i-1;
}

void VeryLongInteger::operator+(const char *s)
{
	int carry=0;
	int result;
	int digit;
	int i,j;
	digit=count(s);
	for (i=digit,j=148;i>=0;i--,j--)
	{
		result=s[i]-'0'+okok[j]-'0'+carry;
		okok[j]=result%10+'0';
		carry=result/10;
	}
	while (carry)
	{
		result=okok[j]-'0'+1;
		okok[j]=result%10+'0';
		carry=result/10;
		j--;
	}
}

main()
{
	VeryLongInteger result;
	char s[150];
	while (cin>>s && s[0]!='0' || s[1]!='\0')
		result+s;
	cout<<result<<endl;
	return 0;
}



