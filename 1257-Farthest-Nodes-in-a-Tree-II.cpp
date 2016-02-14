#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <string.h>

#define vii vector < vector < pair <int, int> > > 
using namespace std;

enum consts  {N = 30000};
vii a;

int vis[N + 5];
int dis[N + 5];
int maxi;
int n;

int explore(int i, int d)
{
	int x;
	int y;
	int w;
	
	dis[i] = d;

	for (int j = 0; j < a[i].size(); j++) {
		x = a[i][j].first;
		w = a[i][j].second;

		if(!vis[x]) {
			vis[x] = 1;
			explore(x, d + w);
		}

	}


}



int routine(int start)
{
	int ans;

	memset(vis, 0, sizeof vis);
	memset(dis, 0, sizeof dis);
	
	maxi = -1;
	
	vis[start] = 1;
	explore(start, 0);
	
	for (int i = 0; i < n; i++) {
		if(dis[i] > maxi) {
			maxi = dis[i];
			ans = i;
		}
	}

	return ans;

}

int main()
{
	int t;
	int m;
	int x;
	int y;
	int w;

	int c[N+5];

	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &n);

		vii temp(n+5);
		swap(temp, a);

		for (int i = 0; i < n - 1; i++) {
			scanf("%d", &x);
			scanf("%d", &y);
			scanf("%d", &w);

			a[x].push_back(make_pair(y, w));
			a[y].push_back(make_pair(x, w));
		}
		
		int k1 =  routine(0);
		int k2 = routine(k1);

		for(int i = 0; i < n; i++) {
			c[i] = dis[i];
		}
		
		int k3 = routine(k2);
	
		printf("Case %d:\n", cs);

		for (int i = 0; i < n; i++) {
			printf("%d\n", max(dis[i], c[i]));
		}



	}

}




