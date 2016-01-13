#include <iostream>
#include <stdio.h>
#include <string.h>
#define N 10005
using namespace std;

int main()
{

	int t;
	int a[N];
	long long bb;
	long long sum[N];
	int m;
	long long maxi;
	int n;
	
	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &n);
		scanf("%d", &m);

		sum[n ] = 0;
		maxi = -1;
		bb = 0;		
		int j;
		j = 0;

		for (int i = 0; i < n; i++) {
			scanf("%d", a + i);
		}

		for (int i = n - 1; i >= 0; i--) {
			sum[i] = sum[i + 1] + a[i ];
		}

		for (int i = 0; i < n; i++) {
		//	cout << sum[i] << " ";
		}

	//	cout << endl;

		for (int i = 0; i < n; ) {
			if(bb + a[i] <= maxi) {
				bb = bb + a[i];
				i++;
			}
			else {
				if((double)(bb + a[i]) <= (double) sum[i] / (m - (j + 1))) {
					bb = bb + a[i];
					maxi = max(maxi, bb);
					i++;
				}
				else {
					bb = 0;
				}

			}
		}

		printf("Case %d: %lld\n", cs, maxi);

	}


}

