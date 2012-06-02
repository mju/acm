#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <stdio.h>

#include <cmath>

double absolute(double key)
{
	return key>0?key:-key;
}

void calculate(double a,double b,double c,double d,double e,double f)
{
	const double PI=3.141592653589793;
	double x,y,x1,y1;
	double m,m1;
	double d1,d2;
	double answerX,answerY;
	double temp,temp1;
	double radius;
	char aa,bb,cc;
	x=(a+c)/2;
	y=(b+d)/2;
	x1=(a+e)/2;
	y1=(b+f)/2;
	if (a-c==0)
	{
		answerY=y;
		if (b-f==0) answerX=x1;
		else
		{
			temp1=(b-f)/(a-e);
			if (temp1!=0) m1=-1.0/((b-f)/(a-e));
			else m1=0.0;
			d2=-x1*m1+y1;
			answerX=(answerY-d2)/m1;
		}
	}
	else if (a-e==0) 
	{
		answerY=y1;
		if (b-d==0) answerX=x;
		else
		{
			temp=(b-d)/(a-c);
			if (temp!=0) m=-1.0/((b-d)/(a-c));
			else m=0.0;
			d1=-x*m+y;
			answerX=(answerY-d1)/m;
		}
	}
	if (b-d==0)
	{
		answerX=x;
		m1=-1.0/((b-f)/(a-e));
		d2=-x1*m1+y1;
		answerY=m1*answerX+d2;
	}
	else if (b-f==0)
	{
		answerX=x1;
		m=-1.0/((b-d)/(a-c));
		d1=-x*m+y;
		answerY=m*answerX+d1;
	}
	else
	{
		temp=(b-d)/(a-c);
		temp1=(b-f)/(a-e);
		if (temp!=0) m=-1.0/temp;
		else m=0.0;
		if (temp1!=0) m1=-1.0/temp1;
		else m1=0.0;
		d1=-x*m+y;
		d2=-x1*m1+y1;
		answerX=(d2-d1)/(m-m1);
		answerY=m1*answerX+d2;
	}
	radius=sqrt((a-answerX)*(a-answerX)+(b-answerY)*(b-answerY));

	if (answerX<=0) aa='+';
	else aa='-';
	if (answerY<=0) bb='+';
	else bb='-';
	if (radius*radius>answerX*answerX+answerY*answerY) cc='-';
	else cc='+';

	answerX=absolute(answerX);
	answerY=absolute(answerY);

	printf("(x %c %.3f)^2 + (y %c %.3f)^2 = %.3f^2\n",aa,answerX,bb,answerY,radius);
	printf("x^2 + y^2 %c %.3fx %c %.3fy %c %.3f = 0\n",aa,answerX*2.0,bb,answerY*2,cc,absolute(answerX*answerX+answerY*answerY-radius*radius));
	cout<<endl;
}

main()
{
	double a,b,c,d,e,f;
	while (cin>>a>>b>>c>>d>>e>>f) calculate(a,b,c,d,e,f);
	return 0;
}
