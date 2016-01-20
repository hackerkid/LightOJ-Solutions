#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#define unset(x, i) (x & ~(1 << i))
#define set(x, i) (x | ((1 << i)))
#define check(x, i) (x & (1 << i))
using namespace std;


int base;
int by;
int n;
int a[30];
int rem[25];
int l;
unsigned long long dp[1 << 16][20];
unsigned long long pow[20];
bool vis[1 << 16];

unsigned long long explore(unsigned long long mask)
{
	
	if(vis[mask] == 1 or mask == 0) {
		return 0;
	}
	
	
	vis[mask] = 1;

	for (int i = 0; i < by; i++)
		dp[mask][i] = 0;

	for (int i = 0; i < base; i++) {
		if(check(mask, i)) {
			l--;
			explore(unset(mask, i));
			l++;
			for (int j = 0; j < by; j++) {
				dp[mask][(pow[l - 1] * i + j) % by] += dp[unset(mask, i)][j];
			}
		}
	}
}

int main()
{

	int t;
	char c;
	char temp[20];
	unsigned long long mask;
	scanf("%d", &t);
	
	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &base);
		scanf("%d", &by);
		scanf("%s", temp);
		
	
		n = strlen(temp);
		l = n;
		pow[0] = 1;
		mask = 0;
		memset(dp, 0, sizeof dp);
		memset(vis, 0, sizeof vis);

		for (int i = 1; i <= n; i++) {
			pow[i] = pow[i-1] * base;
			pow[i] = pow[i] % by;
		}
		

		for (int i = 0; i < n; i++) {
			if(isalpha(temp[i])) {
				a[i] = (temp[i] - 'A') + 10;
			}
			else {
				a[i] = (temp[i] - '0');
			}
			mask = set(mask, a[i]);
		}


		dp[0][0] = 1;
		explore(mask);
		printf("Case %d: %llu\n", cs, dp[mask][0]);

	}
}
			


	

