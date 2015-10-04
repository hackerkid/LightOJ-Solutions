#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main()
{

	long long x1;
	long long y1;
	long long x2;
	long long y2;
	long long t;
	long long dx;
	long long dy;
	long long up;
	long long down;
	long long gcd;
	long long ans;

	
	scanf("%lld", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%lld", &x1);
		scanf("%lld", &y1);
		scanf("%lld", &x2);
		scanf("%lld", &y2);
	
		dx = abs(x2 - x1);
		dy = abs(y2 - y1);

		if(dx == 0 and dy == 0) {
			printf("Case %d: 1\n",cs );
			continue;
		}

		if(dx == 0) {
			printf("Case %d: %lld\n",cs, dy+1 );
			continue;
		}
		
		if(dy == 0) {
			printf("Case %d: %lld\n",cs, dx+1 );
			continue;
		}
		
		gcd = __gcd(dx, dy);
		up = dx / gcd;
		down = dy / gcd;
		ans = 1 + (dy / down);

		printf("Case %d: %lld\n", cs, ans);

	}


}

