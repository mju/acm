#include <iostream>

using std::cout;
using std::cin;
using std::endl;

main()
{
int i;
int count;
char s[10000];
while (cin.getline(s,10000,'\n'))
{
// cout<<s;
count=0;
for (i=0;s[i]!='\0';i++)
{
if ( ( ( s[i]>=65 && s[i]<=90 ) || ( s[i]>=97 && s[i]<=122 ) ) && ( s[i+1]<65 || ( s[i+1]>90 && s[i+1]<97 ) || s[i+1]>122 ) ) 
count++;
}
cout<<count<<endl;
}
return 0;
}

