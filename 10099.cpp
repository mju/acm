#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void initial(int n,int map[][100])
{
	int i,j;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			map[i][j]=0;
}

void warshall(int n,int map[][100])
{
	int i,j,k;
	for (k=0;k<n;k++)
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				if (!map[i][j] || map[i][j]<(map[i][k]>map[k][j]?map[k][j]:map[i][k]))
					if (map[i][k] && map[k][j])
						map[i][j]=map[i][k]>map[k][j]?map[k][j]:map[i][k];
}

main()
{
	int N,R;
	int c1,c2,P;
	int	map[100][100];
	int i,j=1;

	while (cin>>N>>R && N || R)
	{
		initial(N,map);
		for (i=0;i<R;i++)
			cin>>c1>>c2>>P,map[c1-1][c2-1]=map[c2-1][c1-1]=P;
		warshall(N,map);
		cin>>c1>>c2>>P;
		if (P%(map[c1-1][c2-1]-1))
			cout<<"Scenario #"<<j<<endl<<"Minimum Number of Trips = "<<P/(map[c1-1][c2-1]-1)+1<<endl<<endl;
		else cout<<"Scenario #"<<j<<endl<<"Minimum Number of Trips = "<<P/(map[c1-1][c2-1]-1)<<endl<<endl;
		j++;
	}
	return 0;
}


