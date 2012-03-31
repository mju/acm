#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#define N 2001
#define M 1000

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
      
      initial(table,temp,length);

      while (cin>>key)
            cout<<table[key]<<endl;
      return 0;
}
