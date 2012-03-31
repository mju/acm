#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#define N 32768

int answer(int *a,int n)
{
    int i,j=0;
    int length;
    int temp,k;
    int last[N];
    int left,right,middle;
    
    while (j<2)
    {
        if (j) last[0]=a[n-1];
        else last[0]=a[0];
        for (i=1,temp=0;i<n;i++)
        {
            if (j) k=n-i-1;
            else k=i;

            if (a[k]<last[0]) last[0]=a[k];
            else if (a[k]>last[temp]) last[++temp]=a[k];
            else
            {
                left=0,right=temp;
                while (left!=right-1)
                {
                      middle=(left+right)/2;
                      (a[k]<last[middle])?right=middle:left=middle;
                }
                last[right]=a[k];
            }
        }
        if (j==0) length=temp;
        else if (temp>length) length=temp;
        j++;
    }
        
    return length+1;
}

main()
{
      int i,n=0;
      int a[N];
      
      while (++n)
      {
            for (i=0;cin>>a[i] && a[i]!=-1;i++);
            if (i==0) break;
            cout<<"Test #"<<n<<':'<<endl<<"  maximum possible interceptions: "<<answer(a,i)<<endl<<endl;
      }
      return 0;
}
            
            
            
            
            
            
