#include <iostream>
#include <vector>
#include <utility>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;


int n;
int k;
int vis[20];
int a[20][20];

int ans[20][(1 << 16) + 1];
int check(int x, int i)
{
	return (x & (1 << i));

}

int set(int x, int i)
{
	x = x ^ (1 << i);

	return x;
}

int explore(int i, int x)
{
	int k;
	int temp;

	k = 1 << (n + 1);
	k--;


	if(x == k) {
		return a[i][0];
	}
	
	if(ans[i][x] != -1) {
		return ans[i][x];
	}

	int mini = INT_MAX;

	for (int j = 1; j <= n; j++) {
		if(vis[j] == 0) {
			x = set(x, j);
			vis[j] = 1;
			temp = a[i][j] + explore(j, x);
			mini = min(mini, temp);
			x = set(x, j);
			vis[j] = 0;
		}


	}

	ans[i][x] = mini;
	return mini;

}


int main()
{

	int r;
	int c;
	int t;
	char cc;


	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &r);
		scanf("%d", &c);
		vector <pair <int, int> > gr(20);
		n = 0;

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> cc;
				
				if(cc == 'x') {
					gr[0] = make_pair(i, j);
					continue;
				}

				if(cc == 'g') {
					n++;
					gr[n] = make_pair(i, j);
				}

			}


		}
		for (int i = 0; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				a[i][j] = a[j][i]  = max(abs(gr[i].first - gr[j].first) , abs(gr[i].second - gr[j].second));
			}

		}
		
		memset(ans, -1, sizeof(ans));	
		printf("Case %d: %d\n",cs, explore(0, 1));

	}


}

