#include <stdio.h>
#include <limits.h>
#define INF 10000000
using namespace std;
int a[102][102];
void setup()
{

	for (int i = 0; i < 101; i++) {
		for(int j = 0; j < 101; j++) {
			a[i][j] = INF;
		}

	}
}
int min(int x, int y)
{
	if(x < y) {
		return x;
	}

	return y;
}
int main()
{
	int n;
	int m;
	int x;
	int y;
	int w;
	int t;

	scanf("%d", &t);

	for(int p = 1; p <= t; p++) {
		setup();
		scanf("%d", &n);
		scanf("%d", &m);

		for (int i = 0; i < m; i++) {
			scanf("%d", &x);
			scanf("%d", &y);
			scanf("%d", &w);

			a[x][y] = min(w, a[x][y]);
		}

		for (int k = 1; k <= n; k++) {
			for(int i = 0; i <= n; i++) {
				for (int j = 0; j <=n; j++) {
					if(a[i][j] > a[i][k] + a[k][j]) {
						a[i][j] = a[i][k] + a[k][j];
					}

				}

			}

		}

		if(a[1][n] != INF) {
			printf("Case %d: %d\n",p, a[1][n]);
		}

		else {
			printf("Case %d: Impossible\n", p);
		}

	}


}





