#include <fstream>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{

	int t;
	int n;
	int x;
	int y;
	int w;
	int kmax;
	int ans[101][101][101];
	fstream cin;
	cin.open("wow.in", ios::in);

	cin >> t;
	//scanf("%d", &t);

	for (int j = 1; j <= t; j++) {
	//	scanf("%d", &n);
	//	scanf("%d", &w);
	//	scanf("%d", &kmax);
		map <int, int> a;
		vector <int> inp;
		cin >> n >> w >> kmax;

		for (int i = 0; i < n; i++) {
		//	scanf("%d", &x);
		//	scanf("%d", &y);
			cin >> x >> y;
			if(!a.count(y)) {
				a[y] = 1;
				inp.push_back(y);
			}

			else {
				a[y]++;
			}

		}

		sort(inp.begin(), inp.end());

		for (int i = n; i >= 0; i--) {
			for (int k = kmax; k >= 0; k--) {
				for (int j = n; j >= 0; j--) {
					if(i == n) {
						ans[i][k][j] = 0;
						continue;
					}

					if(j == n) {
						ans[i][k][j] = 0;
						continue;
					}

					if(k == kmax) {
						ans[i][k][j] = 0;
						continue;
					}

					if(inp[i] > w + inp[j]) {
						x = a[inp[i]] + ans[i + 1][ k + 1][i];
						y = ans[i + 1][k][j];
						cout << x << "<- x  " << y << "y <- "<<endl;
						ans[i][k][j] = max(x, y);
						continue;
					}

					else {
						ans[i][k][j] = a[inp[i]] + ans[i+1][k][j];
						cout << ans[i][k][j]<<endl;
					}

				}

			}


		}

		printf("Case %d: %d\n", j, ans[0][0][0]);


	}


}









