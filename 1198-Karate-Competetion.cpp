#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;


bool comp(int a, int b)
{

	if(a > b ) {
		return 1;
	}

	return 0;
}

int main()
{

	int t;
	int n;
	int x;
	int ans[100][100];
	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {

		scanf("%d", &n);
		vector <int > a;
		vector <int > b;

		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			a.push_back(x);
		}
		
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			b.push_back(x);
		}

		sort(a.begin(), a.end(), comp);
		sort(b.begin(), b.end(), comp);

		for (int i = n; i >= 0; i--) {
			for (int j = n; j >= 0; j--) {
				
				if(i == n or j == n) {
					ans[i][j] = 0;
					continue;
				}

				if(a[i] > b[j]) {
					ans[i][j] = 2 + ans[i+1][j+1];
					continue;
				}

				if(a[i] == b[j]) {
					ans[i][j] = max(ans[i][j+1], 1 + ans[i+1][j+1]);
					continue;
				}

				if(a[i] < b[j]) {
					ans[i][j] = max(ans[i+1][j], ans[i][j+1]);
				}

				


			}


		}

		printf("Case %d: %d\n", cs, ans[0][0]);


	}


}




					

		



