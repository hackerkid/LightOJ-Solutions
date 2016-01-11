#include <iostream>
#include <stdio.h>
#include <string.h>
#define N 1000
using namespace std;

int a[N + 5];
long long dp[N+5][2];

int n;

long long explore(int i, int one)
{
	
	long long x;
	long long y;

	if(i >= n) {
		return 0;
	}

	if(i == n-1 and one == 1) {
		return 0;
	}
	
	if(dp[i][one] != -1) 
		return dp[i][one];

	x = explore(i+1, one);

	if(i == 0) {
		one = 1;
	}

	y = explore(i+2, one) + a[i];

	return dp[i][one] = max(x, y);

}



int main()
{

	int t;
	
	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &n);
		memset(dp, -1, sizeof dp);

		for (int i = 0; i < n; i++) {
			scanf("%d", a + i);
		}
		
		printf("Case %d: %lld\n", cs, explore(0, 0));
	}



}
	

