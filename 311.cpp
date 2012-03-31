#include <iostream>

using std::cout;
using std::cin;
using std::endl;

main()
{
	int one,two,three,four,five,six;
	int total;
	while (cin>>one>>two>>three>>four>>five>>six && one || two || three || four || five || six)
	{
		total=0;
		total=total+six+five+four;
		if (three!=0 && three%4)
			total=total+(three/4+1);
		else total=total+(three/4);
		one=one-five*11;
		two=two-four*5;
		if (one>0 && two<0)
			one=one-(-1)*two*4;
		three%=4;
		if (two>=0)
		{
			if (two!=0 && three!=0) two=two-(2*(4-three)-1);
			if (three==3) one=one-5;
			if (three==2) one=one-6;
			if (three==1) one=one-7;
			if (two<0) one=one-(-1)*two*4;
			if (one<0) one=0;
			if (two<0) two=0;
			total=total+(two*4+one)/36;
			if ((two*4+one)%36) total++;
			one=0,two=0;
		}
		if (one>=1)
		{
			total=total+(one/36);
			if (one%36) total++;
		}
		cout<<total<<endl;
	}
	return 0;
}
