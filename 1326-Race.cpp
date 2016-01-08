#include <iostream>
#include <stdio.h>
#define N 1003
#define MOD 10056
using namespace std;

long long dp[N+5];
long long count[N + 5];


int main()
{

	int n;
	int t;
	
	long long sum;
	
	count[1] = 1;
	dp[1] = 1;

	for (int i = 2; i <= N; i++) {
		sum = 1;
		for (int j = i; j >= 2; j--) {
			count[j] = (j * count[j]) % MOD + (j * count[j - 1]) % MOD;
			sum = (count[j] + sum) % MOD;
		}

		dp[i] = sum;
		dp[i] = dp[i] % MOD;
	}
	
	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &n);
		printf("Case %d: %d\n", cs, dp[n]);
	}

}

	

	
