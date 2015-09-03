#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
 
int k;
int n;
int a[109];
int dp[10009];
 
int main()
{
 
    int t;
    int mod;
 
    mod = 1e8 + 7;
    scanf("%d", &t);   
 
    for (int cs = 1; cs <= t; cs++) {
        scanf("%d", &n);
        scanf("%d", &k);
 
 
        for (int i = 0; i < n; i++) {
            scanf("%d", a + i);
        }
 
        memset(dp, 0, sizeof dp);
		dp[0] = 1;

		for (int i = 0; i < n; i++) {
			for (int j = a[i]; j <= k; j++) {
				dp[j] += dp[j - a[i]];
				dp[j] = dp[j] % mod;
			}

		}

 
        printf("Case %d: %d\n", cs, dp[k]);
 
    }
 
}
 
