#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <bits/stdc++.h>
using namespace std;
int x;
int y;

vector <int> pr;



	
int main()
{

	int t;
	int primes[100];
	int temp;

	memset(primes, 0, sizeof(primes));

	for (int i = 2; i <= 1000; i++) {
		
		if(primes[i] == 0) {
			
			for (int j = 2 * i; j <= 1000; j = j + i) {
				primes[j] = 1;
			}

		}

	}

	for (int i = 2; i <= 1000; i++) {
		if(primes[i] == 0) {
			pr.push_back(i);
		}
	}
	cout << pr.size() << endl;
	scanf("%d", &t);

	
	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &x);
		scanf("%d", &y);

		int ans[2000];

		for(int i = 0; i <= y; i++) {
			ans[i] = INT_MAX;
		}

		ans[x] = 0;

		int k;

		for (int i = x + 1; i <= y; i++) {
			for (int j = 0; j < pr.size(); j++) {

				k = pr[j];

				if(((i - k) % k == 0) and (i-k != k) and i - k >= x and ans[i-k] != INT_MAX) {
					if(ans[i] > 1 + ans[i-k]) {
						ans[i] = min(ans[i], 1 + ans[i-k]);

						//cout << "k " << k << " " << ans[i-k] << endl;
					}
				}

			}

			//cout << i << " "<<ans[i] << endl;

		}

		if(ans[y] != INT_MAX) {
			printf("Case %d: %d\n", cs, ans[y]);
		}

		else {
			printf("Case %d: -1\n", cs);
		}
		

		
	}

}

		



