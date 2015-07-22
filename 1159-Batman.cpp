#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{

	int t;
	int m;
	int n;
	int p;

	char a[100];
	char b[100];
	char c[100];
	int maxi;	

	int ans[100][100][100];
	

	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%s", a);
		scanf("%s", b);
		scanf("%s", c);

		m = strlen(a);
		n = strlen(b);
		p = strlen(c);

		for (int i = m; i >= 0; i--) {
			for (int j = n; j >= 0; j--) {
				for (int k = p; k >= 0; k--) {
					
					if(i == m or j == n or k == p) {
						ans[i][j][k] = 0;
						continue;
					}

					if(a[i] == b[j] and b[j] == c[k]) {
						ans[i][j][k] = 1 + ans[i+1][j+1][k+1];
						continue;
					}	

					maxi = -1;

					maxi = max(ans[i+1][j][k], maxi);
					maxi = max(ans[i][j+1][k], maxi);
					maxi = max(ans[i][j][k+1], maxi);
					maxi = max(ans[i+1][j+1][k], maxi);
					maxi = max(ans[i+1][j][k+1], maxi);
					maxi = max(ans[i][j+1][k+1], maxi);

					ans[i][j][k] = maxi;
				}

			}

		}



		printf("Case %d: %d\n", cs, ans[0][0][0]);

	}


}

