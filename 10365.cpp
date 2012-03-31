#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <cmath>

int calculate(int *p)
{
    int total=0;
    total+=(p[0]*2*p[1]+2*p[1]*p[2]+2*p[0]*p[2]);
    return total;
}

int solve(int key)
{
    if (!key) return 0;
    int p[3];
    int max;
    int i;
    max=(int)pow(key,1.0/2.9);
    for (i=max;i>0;i--)
        if (key%i==0)
        {
            p[0]=i,key/=i;
            break;
        }
    for (i=(int)sqrt(key+1);i>0;i--)
        if (key%i==0)
        {
            p[1]=i,p[2]=key/i;
            break;
        }  
    for (i=(int)sqrt(p[0]*p[1]+1);i>0;i--)
        if (p[0]*p[1]%i==0)
        {
                p[1]=p[0]*p[1]/i,p[0]=i;
                break;
        }     
        cout<<p[0]<<" "<<p[1]<<" "<<p[2]<<endl;              
    return calculate(p);
}

main()
{
    int N;
    int key;
    int i;
    cin>>N;
    for (i=1;i<=N;i++)
        cin>>key,cout<<solve(key)<<endl;
    return 0;
}    
                
    
    
        
         
    
