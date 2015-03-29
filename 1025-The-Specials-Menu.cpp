#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

char str[100];
long long dp[100][100];

long long wow(int i, int j)
{
	if(j < i) {
		return 0;
	}

	if(i == j ) {
		return 1;
	}

	if(dp[i][j] != -1) {
		return dp[i][j];
	}

	if(str[i] == str[j]) {
		return dp[i][j] = 1 +  wow(i+1, j) + wow(i, j-1);
	}

	else {
		return dp[i][j] = wow(i+1, j) + wow(i, j-1) - wow(i+1, j-1);

	}

}


int main()
{

	int t;
	int n;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%s", str);
		memset(dp, -1, sizeof(dp));
		n = strlen(str) - 1;
		printf("Case %d: %lld\n", i, wow(0, n));

	}


}
