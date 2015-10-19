#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{

	int t;
	long long m;
	long long n;
	long long ans;

	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%lld %lld", &n, &m);
		ans = (n * m ) / 2;
		printf("Case %d: %lld\n", cs, ans);
	}

}
