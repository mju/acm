#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#define N 2001
#define M 1002

int compa(char *a,char *b)
{
     int i;
     for (i=0;a[i]!='\0';i++)
         if (a[i]>b[i]) return 1;
         else if (a[i]<b[i]) return 2;
     return 0;
}

int add(char table[][M],char *temp,int *length,int no)
{
    int i=length[no-2]-1;
    int j=length[no-1]-1;
    int k;
    int carry=0;
    
    for (k=0;i>=0 || j>=0;i--,j--,k++)
    {
        if (i>=0 && j>=0) carry+=table[no-2][i]-'0'+table[no-1][j]-'0';
        else if (i>=0) carry+=table[no-2][i]-'0';
        else carry+=table[no-1][j]-'0';
        
        temp[k]=carry%10+'0';
        carry/=10;
    }
    if (carry) temp[k++]=carry+'0';
    length[no]=k;
    
    for (i=k-1,j=0;i>=0;i--,j++)
        table[no][j]=temp[i];
    table[no][j]='\0';
}
        
void initial(char table[][M],char *temp,int *length)
{
     int i;
     
     table[0][0]='0',table[0][1]='\0',length[0]=1;
     table[1][0]='1',table[1][1]='\0',length[1]=1;
     table[2][0]='1',table[2][1]='\0',length[2]=1;
     
     for (i=3;i<N;i++)
         add(table,temp,length,i);
}
     
main()
{
      int key;
      char table[N][M];
      char temp[M];
      int length[N];
      char a[M],b[M];
      int counter;
      int length1,length2;
      int i;
      
      initial(table,temp,length);

      while (cin>>a>>b && a[0]!='0' || b[0]!='0')
      {
            counter=0;
            for (i=0;a[i]!='\0';i++);
            length1=i;
            for (i=0;b[i]!='\0';i++);
            length2=i; 
            for (i=2;i<N;i++)
                if (length[i]>=length1)
                {
                   if (length[i]==length1)
                   {
                      if (compa(table[i],a)==0 || compa(table[i],a)==1) break;
                   }
                   else break;
                }
            counter=i;
            for (;i<N;i++)
                if (length[i]>=length2)
                {
                   if (length[i]==length2)
                   {
                      if (compa(table[i],b)==1) break;
                   }
                   else break;
                }
            cout<<i-counter<<endl;
      }               
      return 0;
}
