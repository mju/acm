#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int calculate(int a,int b,int c)
{
	int n=b,i=1;
	while (n/c!=b || n%c!=0)
		n=n%c*a+n/c,i++;
	return i;
}

main()
{
	int a,b,c;
	while (cin>>a>>b>>c)
		cout<<calculate(a,b,c)<<endl;
	return 0;
}

/*
  ���D�O�ΰ��k�Ӻ⪺
  �p�Gxyz���H�Y�ƫ�|�ܬ�
  zxy��zxy/�Y�ƴN�Oxyz*/
	

	
		

