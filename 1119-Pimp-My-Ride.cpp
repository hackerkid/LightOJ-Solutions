#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <string.h>
using namespace std;

#define set(x, i) (x | (1 << i))
#define check(x, i) (x & (1 << i))

int a[20][20];
long long dp[20][2 << 16];
int n;

int explore(int i, int x)
{
	
	int ok;
	int sum;
	int mini = INT_MAX;

	sum = 0;
	ok = 0;
	if(dp[i][x] != -1) {
		return dp[i][x];
	}
	for (int j = 1; j <= n; j++) {
		if(check(x, j)) {
			sum += a[i][j];
		}
		else {
			ok = 1;
		}


	}

	if(ok == 0) {
		return sum;
	}

	for (int j = 1; j <= n; j++) {
		if(check(x, j) == 0) {
			mini = min(mini, explore(j, set(x, j)));
		}
	}

	mini = mini + sum;

	return dp[i][x] = mini;

}


int main()
{

	int t;

	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &n);
		memset(a, 0, sizeof a);
		memset(dp, -1, sizeof dp);

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &a[i][j]);
			}
		}

		printf("Case %d: %d\n", cs, explore(0, 0));
	}
}

