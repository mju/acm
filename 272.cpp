
 #include <iostream>
#include <stdio.h>

using std::endl;
using std::cout;
using std::cin;

main()
{
	int i;
int count=1;
char s[1000];
while (gets(s)!=NULL)
{
for (i=0;s[i]!='\0';i++)
{
if (s[i]=='"' && count%2==1)
{
cout<<"``";
count++;
}
else if (s[i]=='"' && count%2==0)
{
cout<<"''";
count++;
}
else cout<<s[i];
}
cout<<endl;
}
return 0;
}
