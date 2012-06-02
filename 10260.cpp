#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void answer(char *s)
{
    int predecessor=0;
    int i;
    
    for (i=0;s[i]!='\0';i++)
    {
        if ((s[i]=='B' || s[i]=='F' || s[i]=='P' || s[i]=='V') && predecessor!=1)
           cout<<'1',predecessor=1;
        else if ((s[i]=='C' || s[i]=='G' || s[i]=='J' || s[i]=='K' || s[i]=='Q' || s[i]=='S' || s[i]=='X' ||s[i]=='Z') && predecessor!=2)
             cout<<'2',predecessor=2;
        else if ((s[i]=='D' || s[i]=='T') && predecessor!=3)
             cout<<'3',predecessor=3;
        else if (s[i]=='L' && predecessor!=4)
             cout<<'4',predecessor=4;
        else if ((s[i]=='M' || s[i]=='N') && predecessor!=5)
             cout<<'5',predecessor=5;
        else if (s[i]=='R' && predecessor!=6)
             cout<<'6',predecessor=6;
        else if (s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='H' || s[i]=='W' || s[i]=='Y')
             predecessor=0;
    }
    cout<<endl;
}

main()
{
      char s[30];
      
      while (cin>>s)
            answer(s);
      return 0;
}
