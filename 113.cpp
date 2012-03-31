#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <cmath>

main()
{
	double n,k;
	while (cin>>n>>k)
	{
		cout.precision(20);
		cout<<pow(k,1/n)<<endl;
	}
	return 0;
}
/*#include<stdio.h>
#include<math.h>
void main( void )
{
	double n , k ;
	while( scanf( "%lf %lf" , &n , &k ) == 2 ){
		printf( "%.0lf\n" , pow( k , (double)1/n ) ) ;
	}
}*/