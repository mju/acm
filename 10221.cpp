#include <iostream>

using std::cout;
using std::cin;
using std::endl;


#include <stdio.h>
#include <cmath>

main()
{
	int s,a;
	const double PI=3.141592653589793;
	const int radius=6440;
	double degree;
	double answer;
	char unit[4];
	while (cin>>s>>a>>unit)
	{
		s+=radius;
		if (strcmp(unit,"min")==0) degree=a/60.0;
		else degree=a;
		if (degree>=360.0 || degree<0)
		{
			while (degree>=0) degree-=360.0;
			degree+=360.0;
		}
		if (degree>180) degree=360-degree;
		answer=2.0*s*PI*degree/360.0;
		printf("%.6f ",answer);
		answer=2.0*s*sin(PI*degree/360.0);
		printf("%.6f\n",answer);
	}
	return 0;
}


