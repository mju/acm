#include <iostream>

using std::cout;
using std::cin;
using std::endl;

main()
{
	const int concrete=7;
	const int array[2][10]={{0,1,5,2,8,3,9,2,8,7},{0,1,7,0,6,1,7,4,8,7}};
	char s[200];
	int i;
	int truth;
	while (cin>>s && s[0]!='0')
	{
		for (i=0;s[i]!='\0';i++) ;
		if (i>1)
		{
			truth=concrete*(s[i-2]-'0');
			truth+=array[(s[i-2]-'0')%2][s[i-1]-'0'];
		}
		else truth=array[0][s[0]-'0'];
		cout<<truth%10<<endl;
	}
	return 0;
}



