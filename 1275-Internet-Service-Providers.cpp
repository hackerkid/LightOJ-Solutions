#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
long long n;
long long c;

long long val(long long x)
{	
	return x * (c - x*n);
}
int main()
{

	int t;
	long long k;
	long long kp;
	
	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%lld %lld",&n, &c);
		
		if(n == 0) {
			printf("Case %d: %d\n", cs, 0);
			continue;
		}

		k = floor(c / (2* n));
		kp = k + 1;

		if(val(k) >= val(kp)) {
			printf("Case %d: %lld\n", cs, k);

		}

		else {
			printf("Case %d: %lld\n", cs, kp);

		}

	}


}


	


