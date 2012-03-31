#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#define N       100

void initial(int table[][N+1],int n,int m)
{
     int i;
     for (i=0;i<=n;i++)
         table[0][i]=0;
     for (i=0;i<=m;i++)
         table[i][0]=0;
}

int DP(char *s1,char *s2,int n,int m,int table[][N+1])
{
    int i,j;
    
    initial(table,n,m);
    
    for (i=0;i<n;i++)
        for (j=0;j<m;j++)
            if (s1[i]==s2[j]) table[i+1][j+1]=table[i][j]+1;
            else table[i+1][j+1]=(table[i][j+1]>table[i+1][j])?table[i][j+1]:table[i+1][j];
    
    return table[n][m];
}

main()
{
      char s1[N+1],s2[N+1];
      int table[N+1][N+1];
      int i,j;
      int n=1;
      
      while (1)
      {
            cin.getline(s1,N+1,'\n');
            if (s1[0]=='#' && s1[1]=='\0') break;
            cin.getline(s2,N+1,'\n');
            
            for (i=0;s1[i]!='\0';i++) ;
            for (j=0;s2[j]!='\0';j++) ;
            
            cout<<"Case #"<<n++<<": you can visit at most "<<DP(s1,s2,i,j,table)<<" cities."<<endl;
      }
      return 0;
}
      
