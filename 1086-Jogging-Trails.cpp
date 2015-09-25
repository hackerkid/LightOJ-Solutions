/*
PROG: fence
ID: bornawe1
LANG: C++
*/
#include <queue>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <algorithm>
#include <string.h>
#include <stdio.h>

#define set(x, n) (x ^ (1 << n))
#define check(x, n) (x & (1 << n))



using namespace std;

int n;
int ind;
int edge_count[1028];
long long floyd[1028][1028];
int ans;
long long dp[ 1 << 17];
int floyd_warshal()
{	
	long long t;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if(floyd[i][j] == 0) {
				floyd[i][j] = INT_MAX;
			}
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if(floyd[i][k] != INT_MAX and floyd[k][j] != INT_MAX) {
					t = floyd[i][k] + floyd[k][j];
					if(t < floyd[i][j]) {
						floyd[i][j] = t;
					}
				}

			}
		}
	}
}


		
long long chinese(int bit)
{
	
	int x;
	long long mini;
	int i;


	
	mini = INT_MAX;
	
	if(bit == 0) {
		return 0;
	}
	
	if(dp[bit] != -1) {
		return dp[bit];
	}

	for(i = 1; i <= n; i++) {
		if(check(bit, i)) {
			break;
		}
	}

	for (int j = i + 1; j <= n; j++) {
		int temp = bit;

		if(check(bit, i) and check(bit, j )) {
			temp = set(temp, i);
			temp = set(temp, j);

			mini = min(mini, floyd[i][j] + chinese(temp));
		}
	}
	

	
	return dp[bit] = mini;
}



int travel(int cs)
{
	int x;
	int y;
	int start;
	long long mini;
	long long w;
	int m;
	int bit;

	

	memset(edge_count, 0, sizeof edge_count);
	memset(dp, -1, sizeof dp);



	
	ans = 0;	
	bit = 0;

	cin >> n;
	cin >> m;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			floyd[i][j] = INT_MAX;
		}
	}
	
	for (int i = 0; i < m; i++) {
		
		
		cin >> x;
		cin >> y;
		cin >> w;

		ans += w;
		
		floyd[x][y] = min(w, floyd[x][y]);
		floyd[y][x] = min(w, floyd[y][x]);
		
		
		edge_count[x]++;
		edge_count[y]++;
		
	}

	

	floyd_warshal();
	
	
	for (int i = 1; i <= n; i++) {
		if(edge_count[i] % 2 == 1) {
			bit = set(bit, i);
		}

	}
	 ans += chinese(bit);


	 printf("Case %d: %d\n", cs, ans);
}



int main()
{

	int t;

	cin >> t;

	for (int cs = 1; cs <= t; cs++) {
		travel(cs);
	}
	


}
