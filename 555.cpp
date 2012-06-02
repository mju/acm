#include <iostream>

using std::cout;
using std::cin;
using std::endl;

main()
{
	char change[14]={'\0','A','2','3','4','5','6','7','8','9','T','J','Q','K'};
	char poke[53];
	char poke2[53];
	char begin;
	char swne[4]={'S','W','N','E'};
	char cdsh[4][14];
	int p[16]={0,4,2,6,4,0,6,2,0,4,2,6,4,0,6,2};
	cdsh[0][0]='C',cdsh[1][0]='D',cdsh[2][0]='S',cdsh[3][0]='H';
	int i,j,k,a,b,position;
	int aaa,bbb;
	while (cin>>begin && begin!='#')
	{
		cin>>poke>>poke2;
		position=0;
		for (i=0;i<4;i++) 
			if (swne[i]==begin)
			{
				aaa=(i+1)*2;
				break;
			}
		aaa=8-aaa;
		for (i=aaa,bbb=1;bbb<=4;i+=2,position++,bbb++)
		{
			for (a=0;a<4;a++)
				for (b=1;b<14;b++)
					cdsh[a][b]='0';
			for (j=p[i];j<53;j+=8)
			{
				for (k=0;k<4;k++)
					if (poke[j]==cdsh[k][0])
					{
						if (poke[j+1]=='A') poke[j+1]='1';
						if (poke[j+1]=='T') poke[j+1]=':';
						if (poke[j+1]=='J') poke[j+1]=';';
						if (poke[j+1]=='Q') poke[j+1]='<';
						if (poke[j+1]=='K') poke[j+1]='=';
						cdsh[k][poke[j+1]-'0']='1';
						break;
					}
			}
			for (j=p[i+1];j<53;j+=8)
			{
				for (k=0;k<4;k++)
					if (poke2[j]==cdsh[k][0])
					{
						if (poke2[j+1]=='A') poke2[j+1]='1';
						if (poke2[j+1]=='T') poke2[j+1]=':';
						if (poke2[j+1]=='J') poke2[j+1]=';';
						if (poke2[j+1]=='Q') poke2[j+1]='<';
						if (poke2[j+1]=='K') poke2[j+1]='=';
						cdsh[k][poke2[j+1]-'0']='1';
						break;
					}
			}
			cout<<swne[position]<<":";
			for (j=0;j<4;j++)
			{
				for (k=2;k<14;k++)
					if (cdsh[j][k]=='1')
						cout<<" "<<cdsh[j][0]<<change[k];
				if (cdsh[j][1]=='1') cout<<" "<<cdsh[j][0]<<change[1];
			}
			cout<<endl;
		}
	}
	return 0;
}



