#include <iostream>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <queue>
#include <utility>
#include <stdio.h>
using namespace std;

int m;
int n;
int p;
int r;
int f;
int d;
char a[15][15];
bool vis[15][15];
int dis[110][110];


int bfs()
{

	int sofar;
	

	queue < pair <int, int > > q;
	pair <int, int> temp ;

	dis[p * n + r][p * n + r] = 0;
	vis[p][r] = 1;

	temp = make_pair(p, r);

	q.push(temp);

	while(!q.empty()) {

		
		temp = q.front();
		q.pop();

		int i = temp.first;
		int j = temp.second;
		int b;
		int bb;
		
		
		

		if(i < 0 or i >= m or j < 0 or j >= n) {
			cout << "ohey" << endl;
			continue;
		}
	

		sofar = dis[p * n + r][i * n + j];
		
		sofar++;

		if(!((i + 1) < 0 or (i + 1) >= m or (j+2) < 0 or (j+2) >= n)) {
		if(vis[i+1][j+2] == 0) {	
			vis[i+1][j+2] = 1;
			dis[p * n + r][(i+1) * n + (j+2)] = sofar;		
			q.push(make_pair(i+1, j+2));
		}
		}


		if(!((i + 1) < 0 or (i + 1) >= m or (j-2) < 0 or (j-2) >= n)) {
		if(vis[i+1][j-2] == 0) {
			vis[i+1][j-2] = 1;
			dis[p * n + r][(i+1) * n + (j-2)] = sofar;	
			q.push(make_pair(i+1, j-2));	
		}
		}
	
		if(!((i - 1) < 0 or (i - 1) >= m or (j+2) < 0 or (j+2) >= n)) {
		if(vis[i-1][j+2] == 0) {
			vis[i-1][j+2] = 1;
			dis[p * n + r][(i-1) * n + (j+2)] = sofar;	
			q.push(make_pair(i-1, j+2));
		}
		}

		if(!((i - 1) < 0 or (i - 1) >= m or (j-2) < 0 or (j-2) >= n)) {
		if(vis[i-1][j-2] == 0) {
			vis[i-1][j-2] = 1;
			dis[p * n + r][(i-1) * n + j-2] = sofar;
			q.push(make_pair(i-1, j-2));	
		}
		}

		if(!((i +2) < 0 or (i + 2) >= m or (j+1) < 0 or (j+1) >= n)) {
		if(vis[i+2][j+1] == 0) {
			vis[i+2][j+1] = 1;
			dis[p * n + r][(i+2) * n + j+1] = sofar;	
			q.push(make_pair(i+2, j+1));


		}
		}

		if(!((i +2) < 0 or (i + 2) >= m or (j-1) < 0 or (j-1) >= n)) {
		
		if(vis[i+2][j-1] == 0) {
			vis[i+2][j-1] = 1;
			dis[p * n + r][(i+2) * n + j - 1] = sofar;	
			q.push(make_pair(i+2, j-1));
		}
	}

		if(!((i - 2) < 0 or (i - 2) >= m or (j+1) < 0 or (j+1) >= n)) {

		if(vis[i-2][j+1] == 0) {
			vis[i-2][j+1] = 1;
			dis[p * n + r][(i - 2) * n + j + 1] = sofar;	
			q.push(make_pair(i-2, j+1));
		}
	}

	if(!((i - 2 ) < 0 or (i - 2) >= m or (j -1) < 0 or (j-1) >= n)) {

		if(vis[i-2][j-1] == 0) {
			vis[i-2][j-1] = 1;
			dis[p * n + r][(i - 2) * n + j - 1] = sofar;	
			q.push(make_pair(i-2, j-1));
		}

	}

	}


}



	
int main()
{

	int t;
	int k;
	int temp;
	int ans;

	cin >> t;
	for (int cs = 1; cs <= t; cs++) {
		cin >> m;
		cin >> n;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}


		for (int i = 0; i < m * n; i++) {
			for (int j = 0; j < n * m; j++) {
				dis[i][j] = INT_MAX;
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				memset(vis, 0, sizeof(vis));
				p = i;
				r = j;
				if(a[i][j] != '.') {
					vis[i][j] = 1;
					bfs();
					vis[i][j] = 0;
				}
			}
		}
		
		ans = INT_MAX;

		int p;
		int pp;

		for (int i = 0; i < m * n; i++) {
			temp = 0;
			for (int j = 0; j < m * n; j++) {
				p = j / n;
				pp = j % n;


				if(a[p][pp] != '.') {
					k = a[p][pp] - '0';
					if(dis[j][i] != INT_MAX) {
						temp += ceil((double) dis[j][i] / (double) k);
					}

					else {
						temp = INT_MAX;
						break;
					}

				}

			}

			ans = min(ans, temp);

		}

		if(ans == INT_MAX) {
			ans = -1;
		}
		printf("Case %d: %d\n", cs, ans);
		

		


	}

}
