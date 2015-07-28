#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[100];
int dp[100];
int maxi;
int n;

int explore(int sum)
{	
	if(sum <= 0) {
		
		for (int j = maxi; j >= 0; j--) {
			printf("%d", a[j]);
		}

		printf("\n");

		return 0;
	}

	if(sum == 1) {
		a[0] = 1;
		maxi = max(maxi, 0);
		explore(0);
		return 0;
	}

	for (int i = 0; 1; i++) {
		if(dp[i+1] >= sum and dp[i] < sum) {
			a[i+1] = 1;
			sum = sum - (dp[i]+1);
			maxi = max(maxi, i+1);
			explore(sum);
			break;
		}
	}


}



int main()
{

	int j;
	int k;
	int t;
	int temp;

	j = 1; 
	k = 2;

	dp[0] = 1;

	for (int i = 1; i < 44; i++) {
		dp[i] = dp[i-1] + j;
		temp = k;
		k = j + k;
		j = temp;
		
	}
	
	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &n);
		memset(a, 0, sizeof(a));
		maxi = -1;
		printf("Case %d: ", cs);
		explore(n);
	}

}

