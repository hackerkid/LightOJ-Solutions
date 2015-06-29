#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{

	int t;

	long long w;
	long long odd;
	long long even;

	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%lld", &w);
		if(w % 2 != 0) {
			printf("Case %d: Impossible\n", cs);
			continue;
		}

		odd = w / 2;
		even = 2;

		while(odd % 2 == 0) {
			odd = odd / 2;
			even = even * 2;
		}

		printf("Case %d: %lld %lld\n",cs, odd, even); 

	}


}


