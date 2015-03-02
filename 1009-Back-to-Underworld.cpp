#include <iostream>
#include <stack>
#include <string.h>
#include <vector>
#include <stdio.h>
#define N 20004
using namespace std;

int main()
{

	int x;
	int y;
	int ok;
	int count;
	int k;
	int t;
	int n;
	int total;
	int maxi;
	int next;	
	int c0;
	int c1;
	int tt;
	cin >> tt;

	for (int i = 1; i <= tt; i++) {
		vector < vector <int > > g(N);
		int vis[N];
		vector < stack <int> > a(2);
		stack <int> ny;
		memset(vis, -1, sizeof(vis));
		cin >> n;
		total = 0;
		count = 0;

		
		for (int j = 0; j < n; j++) {
			scanf("%d", &x);
			scanf("%d", &y);
			g[x].push_back(y);
			g[y].push_back(x);
			
			if(vis[x] == -1) {
				total++;
				vis[x] = 0;
				ny.push(x);
			}

			if(vis[y] == -1) {
				total++;
				vis[y] = 0;
				ny.push(y);
			}

		}

		next = x;
		vis[next] = 1;
		count = 1;
		maxi = 0;

		while(count < total) {
			c0 = 1;
			c1 = 0;
			//cout << " here " << endl;
			for (int j = 0; j < g[next].size(); j++) {
				t = g[next][j];
				if(vis[t] == 0) {
					c1++;
					a[1].push(t);
					//cout << " a1 pushed from start "<<next<<" "<<t<<endl;
					count++;
					vis[t] = 1;
				}

			}
			while(!a[0].empty() or !a[1].empty()) {

				while(!a[0].empty()) {
					t = a[0].top();
					a[0].pop();
					for (int j = 0; j < g[t].size(); j++) {
						k = g[t][j];
						if(vis[k] == 0) {
							a[1].push(k);
							//cout << " a1 pushed  "<<t<<" "<<t<<endl;
							c1++;
							vis[k] = 1;
							count++;
						}

					}

				}
				
				while(!a[1].empty()) {
					t = a[1].top();
					a[1].pop();
					for (int j = 0; j < g[t].size(); j++) {
						k = g[t][j];
						if(vis[k] == 0) {
							//cout << " a1 pushed  "<<t<<" "<<t<<endl;
							a[0].push(k);
							c0++;
							vis[k] = 1;
							count++;
						}

					}

				}

			}

			maxi += max(c1, c0);
			
			while(!ny.empty()) {
				k = ny.top();
				ny.pop();
				if(vis[k] == 0) {
					next = k;
					//cout << " next guy is "<<next << endl;
					vis[k] = 1;
					count++;
					break;
				}

			}



		}

		printf("Case %d: %d\n", i, maxi);


	}



}

