#include <iostream>
#include <stdio.h>
using namespace std;
int a[10000];
long long k;
int explore(int n)
{

	if(n == 1) {
		return 1;
	}
	
	return (explore(n-1) + k - 1) % n + 1;

}
int main()
{
	int t;
	int dp;
	int n;
	scanf("%d", &t);

	for (int cs = 1; cs <= t;cs++) {
		scanf("%d", &n);
		scanf("%lld", &k);
		
		printf("Case %d: %d\n", cs, explore(n));
	}

}



