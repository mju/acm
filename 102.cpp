#include <iostream>

using std::cout;
using std::cin;
using std::endl;

main()
{
	int data[9];
	int combination[18];
	int i;
	int min;
	int TimeOfMin;
	int total;
	int j;
	int judge=0;
	char *name[6]={"BCG","BGC","CBG","CGB","GBC","GCB"};
	while (1)
	{
		min=999999999;
		for (i=0;i<9;i++) 
			if (!(cin>>data[i]))
			{
				judge=1;
				break;
			}
		if (judge) break;
		combination[0]=combination[3]=data[1]+data[2];
		combination[1]=combination[16]=data[3]+data[4];
		combination[2]=combination[8]=data[6]+data[8];
		combination[4]=combination[10]=data[3]+data[5];
		combination[5]=combination[14]=data[6]+data[7];
		combination[6]=combination[9]=data[0]+data[1];
		combination[7]=combination[13]=data[4]+data[5];
		combination[11]=combination[17]=data[7]+data[8];
		combination[12]=combination[15]=data[0]+data[2];
		for (i=0,j=0;j<6;i+=3,j++) 
		{
			total=combination[i]+combination[i+1]+combination[i+2];
			if (total<min) min=total,TimeOfMin=j;
		}
		cout<<name[TimeOfMin]<<" "<<min<<endl;
	}
	return 0;
}






