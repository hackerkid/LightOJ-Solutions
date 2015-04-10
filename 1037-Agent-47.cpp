#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <limits.h>
#define check(n, pos) (n & (1<<pos))
#define set(n, pos) (n | (1<<pos))

using namespace std;

int power[20];
int n;
int x[20][20];
int dp[1 << 17];

int unset(int a, int i)
{
	int mask;
	mask = 1 << i;
	a = a & ~mask;

	return a; 
}
int wow(int count, int a)
{
	if(count == n) {
		return 0;
	}

	if(dp[a] != -1) {
		return dp[a];
	}


	int maxi;
	int c;
	maxi = INT_MAX;

	for (int i = 0; i < n; i++) {
		if(check(a, i) == 0) {

			for (int j = 0; j <= n; j++) {
				if(check(a, j) != 0 and x[j][i] != 0) {
					a = set(a, i);
					c = (int) ceil((float) power[i] / (float) x[j][i]);
					maxi = min(maxi, c + wow(count + 1, a));
					a = unset(a, i);
				}

			}

		}

	}
	dp[a] = maxi;
	return maxi;


}
					


int main()
{

	int t;
	int a;
	char c;


	scanf("%d", &t);

	for (int cases = 1; cases <= t; cases++) {
		scanf("%d", &n);
		memset(dp, -1, sizeof(dp));
		a = 0;
		a = set(a, n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &power[i]);
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> c;
				x[i][j] = (int) (c - '0');
			}

		}

		for (int i = 0; i < n; i++) {
			x[n][i] = 1;
		}
		printf("Case %d: %d\n",cases, wow(0, a));

	}

}


			


