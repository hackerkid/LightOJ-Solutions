#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main()
{
	int t;
	int x;
	int base;	
	double ans;
	int number_of_digits;
	double wow[1000005];



	cin >> t;

	for(int i = 1; i <= 1000002; i++) {
		wow[i] = wow[i-1] + log(i);
	}


	for (int cases = 1; cases <= t; cases++) {
		cin >> x;
		cin >> base;
		ans = 0;

		if(x == 0 or x == 1) {
			printf("Case %d: %d\n", cases, 1 );
			continue;
		}

		if(x == 2) {
			
			x = 4;
			number_of_digits = 0;

			while(x) {
				x = x / base;
				number_of_digits++;

			}
			printf("Case %d: %d\n", cases, number_of_digits );
			
			continue;
		}

		
		ans = wow[x];

		number_of_digits = ceil(ans/log(base));
		printf("Case %d: %d\n", cases, number_of_digits );
			

			
	

	}
}