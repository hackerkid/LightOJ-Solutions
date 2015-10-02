#include <iostream>
#include <stdio.h>
#include <string.h>
#include <limits.h>
using namespace std;

long long dp[110][110][2];
int a[110];
int n;

long long explore(int l, int r, int chance)
{
	
	long long x;
	long long sum;

	if(l > r) {
		return 0;
	}

	if(dp[l][r][chance] != -1) {
		return dp[l][r][chance];
	}

	if(chance == 0) {
		sum = 0;
		x = INT_MIN;
		
		for (int i = l; i <= r; i++) {
			sum = sum + a[i];
			x = max(x, sum + explore(i+1, r, 1));
		}
		sum = 0;

		for (int i = r; i >= l; i--) {
			sum = sum + a[i];
			x = max(x, sum + explore(l, i-1, 1));
		}

		dp[l][r][chance] = x;
		return x;

	}

	if(chance == 1) {
		sum = 0;
		x = INT_MAX;
		
		for (int i = l; i <= r; i++) {
			sum = sum + -a[i];
			x = min(x, sum + explore(i+1, r, 0));
		}
		sum = 0;

		for (int i = r; i >= l; i--) {
			sum = sum + -a[i];
			x = min(x, sum + explore(l, i-1, 0));
		}

		dp[l][r][chance] = x;
		return x;

	}

}



int main()
{

	int t;

	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		
		memset(dp, -1 , sizeof dp);
		scanf("%d", &n);
				
		for (int i = 0; i < n; i++) {
			scanf("%d", a + i);
		}

		printf("Case %d: %lld\n", cs, explore(0, n-1, 0));

	}

}

