#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <stdio.h>

double bye(int minute,int hours)
{
	double degree=hours;
	degree*=30.0;
	degree-=minute*6.0;
	degree+=minute*1.0/2.0;
	if (degree<0) degree*=-1;
	if (degree>180) degree=360-degree;
	return degree;
}

main()
{
	char s[6];
	int i,total,temp;
	while (cin>>s && s[0]!='0')
	{
		i=total=0;
		while (1)
		{
			if (s[i]>='0' && s[i]<='9')
				total*=10,total+=s[i]-'0';
			else if (s[i]=='\0') break;
			else temp=total,total=0;
			i++;
		}
		printf("%.3f\n",bye(total,temp));
	}
	return 0;
}














