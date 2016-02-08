#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

enum consts { N = 1005};

vector < vector <int> > a;

int n;
int m;
int k;
int city[N];
int vis[N];
int count[N];

int explore(int j, int inc)
{
	
	count[j] += inc;

	for (int i = 0; i < a[j].size(); i++) {
		int x;
		x = a[j][i];
		
		if(vis[x] == 0) {
			vis[x] = 1;
			explore(x, inc);
		}
	}

}

int main()
{
	
	int t;
	int x;
	int y;
	int inc;
	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &k);
		scanf("%d", &n);
		scanf("%d", &m);
			
		vector < vector <int> > temp(N + 5);
		swap(temp, a);
		
		memset(city, 0, sizeof city);
		memset(count, 0, sizeof count);

		for (int i = 0; i < k; i++) {
			scanf("%d", &x);
			city[x]++;
		}

		for (int i = 0; i < m; i++) {
			scanf("%d", &x);
			scanf("%d", &y);
			a[x].push_back(y);
		}

		for (int i = 1; i <= n; i++) {
			memset(vis, 0, sizeof vis);
			if(city[i]) {
				vis[i] = 1;
				inc = city[i];
				explore(i, inc);
			}
		}
		
		int ans;
		ans = 0;

		for (int i = 1; i <= n; i++) {
			if(count[i] >= k)
				ans++;
		}

		printf("Case %d: %d\n", cs, ans);
	}
}
