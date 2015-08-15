#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int n;
int W;
int maxi;

int dp[33][33][33];
int w[33];

int explore(int i, int j,  int sum)
{
	int x;
	int y;

	x = 0;
	y = 0;
	
	if(i == n) {
		return 0;
	}

	if(j == maxi) {
		return 0;
	}

	if(dp[i][j][sum] != -1) {
		return dp[i][j][sum];
	}

	if(sum + w[i] <= W) {
		x = 1 + explore(i+1, j+1, sum + w[i]);
	}
	
	y = explore(i+1, j, sum);

	return dp[i][j][sum] = max(x, y);

}

int main()
{

	int t;
	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &n);
		scanf("%d", &maxi);
		scanf("%d", &W);
		memset(dp, -1, sizeof dp);

		for (int i = 0; i < n; i++) {
			scanf("%d", &w[i]);
		}

		printf("Case %d: %d\n", cs, explore(0, 0, 0));
	}

}
