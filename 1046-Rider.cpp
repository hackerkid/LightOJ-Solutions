#include <iostream>
#include <string.h>
#include <limits.h>
#include <math.h>
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


int explore(int i, int j,int sofar)
{
	int temp;

	temp = INT_MAX;
	
	if(i < 0 or i >= m or j < 0 or j >= n) {
		return INT_MAX;
	}
	
	if(dis[p * n + r][i * n + j] > sofar) {
		dis[p * n + r][i * n + j] = sofar;
	
	}

	if(vis[i+1][j+2] == 0) {
		vis[i+1][j+2] = 1;
		temp = min(explore(i+1, j+2,sofar+1), temp);
		vis[i+1][j+2] = 0;
	}

	if(vis[i+1][j-2] == 0) {
		vis[i+1][j-2] = 1;
		temp = min(explore(i+1, j-2,sofar+1), temp);
		vis[i+1][j-2] =0;
	}
	
	if(vis[i-1][j+2] == 0) {
		vis[i-1][j+2] = 1;
		temp = min(explore(i-1, j+2,sofar+1), temp);
		vis[i-1][j+2] = 0;
	}

	if(vis[i-1][j-2] == 0) {
		vis[i-1][j-2] = 1;
		temp = min(explore(i-1, j-2,sofar+1), temp);
		vis[i-1][j-2] = 0;
	}

	if(vis[i+2][j+1] == 0) {
		vis[i+2][j+1] = 1;
		temp = min(explore(i+2, j+1,sofar+1), temp);
		vis[i+2][j+1] = 0;
	}

	if(vis[i+2][j-1] == 0) {
		vis[i+2][j-1] = 1;
		temp = min(explore(i+2, j-1,sofar+1), temp);
		vis[i+2][j-1] = 0;
	}

	if(vis[i-2][j+1] == 0) {
		vis[i-2][j+1] = 1;
		temp = min(explore(i-2, j+1,sofar+1), temp);
		vis[i-2][j+1] = 0;
	}

	if(vis[i-2][j-1] == 0) {
		vis[i-2][j-1] = 1;
		temp = min(explore(i-2, j-1,sofar+1), temp);
		vis[i-2][j-1] = 0;
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

		memset(dis, 0, sizeof(dis));

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
					vis[i][j] = true;
					explore(i, j, 0);
					vis[i][j] = false;
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
					if(dis[j][i] != INT_MAX) {
						temp += dis[j][i];
					}

					else {
						temp = INT_MAX;
						break;
					}

				}

			}

			ans = min(ans, temp);

		}

		cout << ans << endl;

		}

		


	}

}
