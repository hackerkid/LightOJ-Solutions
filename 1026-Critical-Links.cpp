#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <map>

#define SIZE 10006
using namespace std;

vector < vector <int> > g;
map < pair <int, int>, int > mp;

int vis[SIZE];
int dur[SIZE];
int low[SIZE];
int art[SIZE];
int counter;
int parent[SIZE];

int find_articulation(int x)
{
	int child;
	int y;

	counter++;
	vis[x] = 1;
	child = 0;

	dur[x] = low[x] = counter;

	for (int i = 0; i < g[x].size(); i++) {
		y = g[x][i];
		child++;

		if(vis[y] == 0) {
			parent[y] = x;
			find_articulation(y);
			low[x] = min(low[x], low[y]);

			if(low[y] > dur[x]) {
				if(mp.count(make_pair(min(x, y), max(x, y))) == 0) {
					mp[make_pair(min(x, y), max(x, y))] = 1;
				}

			}
		}

		else {
			if(y != parent[x]) {
				low[x] = min(low[x], dur[y]);
			}
		}

	}


}

int main()
{

	int t;
	int n;
	int m;
	int x;
	int y;
	char c;

	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		
		scanf("%d", &n);

		vector < vector <int> > tg(n + 2);
		map < pair <int, int>, int > tmp;
		swap(mp, tmp);
		
		swap(tg, g);
		memset(parent, -1, sizeof parent);
		memset(vis, 0, sizeof vis);
		memset(art, 0, sizeof art);
		counter = 0;

		for (int i = 0; i <  n; i++) {
			scanf("%d (%d)", &x, &m);

			for (int j = 0; j < m; j++) {
				scanf("%d", &y);
				if(x < y) {
					g[x].push_back(y);
					g[y].push_back(x);
				}

			}

		}

		for (int i = 0; i <= n; i++) {
			if(!vis[i]) {
				find_articulation(i);
			}
		}

		map< pair <int, int>, int >::iterator it;
		
		printf("Case %d:\n", cs);
		printf("%d critical links\n", mp.size());
		for(it = mp.begin(); it != mp.end(); it++) {
			printf("%d - %d\n", it->first.first, it->first.second);
		}



	}

}




