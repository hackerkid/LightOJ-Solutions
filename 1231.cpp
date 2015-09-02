#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
 
int k;
int n;
int a[100];
int c[100];
int dp[100][1008];
 
 
long long  explore(int i, int sum)
{  
    long long ans;
    int mod;
    ans = 0;
 
    mod = 1e8 + 7;
   
    if(sum == k) {
        return 1;
    }
 
    if(i == n) {
        return 0;
    }
 
    if(dp[i][sum] != -1) {
        return dp[i][sum];
    }
   
    for (int j = 0; j <= c[i] and (j * a[i]) + sum <= k; j++) {
        ans += explore(i+1, sum + j * a[i]);
        ans = ans % mod;
    }
 
 
    return dp[i][sum] = ans;
 
}
 
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
 
        for (int i = 0; i < n; i++) {
            scanf("%d", c + i);
        }
 
        memset(dp, -1, sizeof dp);
 
        printf("Case %d: %lld\n", cs, explore(0, 0));
 
    }
 
}
 