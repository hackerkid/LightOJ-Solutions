#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <limits.h>
using namespace std;

int s;
int t;
int n;

vector < vector < pair <int, int> > > g;
int a[110][110];
int parent[110];

int dfs()
{

	int vis[110];
	int top;
	int x;
	
	memset(vis, 0, sizeof vis);

	stack <int> q;
	q.push(s);
	vis[s] = 1;

	
	while(!q.empty()) {
		top = q.top();
		q.pop();
		for (int i = 0; i < g[top].size(); i++) {
			x = g[top][i].first;
			if(a[top][x] > 0 and vis[x] == 0) {
				q.push(x);
				vis[x] = 1;
				parent[x] = top;
			}

		}


	}
	return vis[t] == 1;



}


int main()
{

	int x;
	int y;
	int w;
	int CS;
	int flow;
	int k;
	int c;
	int p;
	int ans;




	scanf("%d", &CS);

	for (int cs = 1; cs <= CS; cs++) {
		scanf("%d", &n);
		scanf("%d", &s);
		scanf("%d", &t);
		scanf("%d", &c);
		
		memset(a, 0, sizeof(a));
		vector < vector < pair <int, int> > > tg(n+2);

		swap(tg, g);
		ans = 0;

		for (int i = 0; i < c; i++) {
			scanf("%d", &x);
			scanf("%d", &y);
			scanf("%d", &w);

			a[x][y] += w;
			a[y][x] += w;
			g[x].push_back(make_pair(y, w));
			g[y].push_back(make_pair(x, w));
		}


		while(dfs()) {
			k = t;

			flow = INT_MAX;
			
			while(k != s) {
				p = parent[k];
				flow = min(flow, a[k][p]);
				k = parent[k];

				
			}
			
			
			k = t;


			while(k != s) {
				p = parent[k];
				a[k][p] -= flow;
				a[p][k] -= flow;
				k = parent[k];
			}

			ans += flow;
		}

		printf("Case %d: %d\n", cs, ans); 
	}


}



