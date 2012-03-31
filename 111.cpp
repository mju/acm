#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#define         N  20

int LIS(int *answer,int *order,int n)
{
    int table[N];
    int maximum=0;
    int i,j;
    int max;
    
    for (i=0;i<n;i++)
    {
        max=0;
        for (j=i-1;j>=0;j--)
            if (table[j]>max && order[answer[i]]>order[answer[j]])
               max=table[j];
        table[i]=max+1;
        if (table[i]>maximum) maximum=table[i];
    }
    
    return maximum;
}

main()
{
      int order[N],answer[N];
      int i;
      int n;
      int temp;
      int judge=1;
      
      for (cin>>n,i=0;i<n;i++)
          cin>>temp,order[i]=temp-1;
          
      while (1)
      {
            for (i=0;i<n && judge;i++)
                if (cin>>temp) answer[temp-1]=i;
                else judge=0;
            if (!judge) break;    
            cout<<LIS(answer,order,n)<<endl;
      }
      return 0;
}
