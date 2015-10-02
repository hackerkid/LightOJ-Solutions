#include <iostream>
#include <stdio.h>
#include <stack>
#include <string.h>

using namespace std;

int inp1[110];
int inp2[110];
int n;
int m;
int a[250][250];
int sor;
int tar;
int flow;
int parent[250];

int dfs()
{
	int x;
	int y;
	int vis[250];

	memset(vis, 0 , sizeof vis);

	stack <int> q;
	q.push(sor);

	while(!q.empty()) {
		x = q.top();
		q.pop();

		for (int i = 0; i <= n + m + 2; i++) {
			if(a[x][i] > 0 and vis[i] == 0) {
				parent[i] = x;
				q.push(i);
				vis[i] = 1;
			}
		}

	}

	return vis[tar] == 1;
}

		



int main()
{
	int t;
	int ans;
	int k;

	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		
		ans = 0;

		scanf("%d", &n);


		
		for (int i = 0; i < n; i++) {
			scanf("%d", inp1 + i);
		}
		
		scanf("%d", &m);

		for (int i = 0; i < m; i++) {
			scanf("%d", inp2 + i);
		}
		
		sor = n + m + 1;
		tar = n + m + 2;

		memset(a, 0, sizeof a);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if(inp2[j] % inp1[i] == 0) {
					a[i][j + n] = 1;
				}

			}

		}

		for (int i = 0; i < n; i++) {
			a[sor][i] = 1;
		}

		for(int i = 0; i < m; i++) {
			a[i + n][tar] = 1;
		}

		while(dfs()) {
			k = tar;


			while(k != sor) {

				a[parent[k]][k] -= 1;
				a[k][parent[k]] += 1;
				k = parent[k];
			}

			ans += 1;
		}

		printf("Case %d: %d\n", cs, ans);

	}


}






