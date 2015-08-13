#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int n;
int p[110];
int w[110];
int dp[10005][105];
int W;

int explore(int sum, int i)
{
	int x;
	int y;
	int z;
	
	x = y = z = 0;

	if(i == n) {
		return 0;
	}

	if(dp[sum][i] != -1) {
		return dp[sum][i];
	}

	
	if(sum + w[i] <= W)
		x = p[i] + explore( sum + w[i], i+1);
	
	if(sum + w[i] <= W)
		y = p[i] + explore(sum + w[i], i);

	z = explore(sum, i+1);

	return dp[sum][i] = max(x, max(y, z));
}

int main()
{

	int t;
	int x;

	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {

		scanf("%d", &n);
		scanf("%d", &W);

		for (int i = 0; i < n; i++) {
			scanf("%d", &p[i]);
			scanf("%d", &x);
			scanf("%d", &w[i]);

			W = W - w[i] * x;
		}

		if(W < 0) {
			printf("Case %d: Impossible\n", cs);
			continue;
		}
		memset(dp, -1, sizeof(dp));

		printf("Case %d: %d\n", cs, explore(0, 0));


	}


}

