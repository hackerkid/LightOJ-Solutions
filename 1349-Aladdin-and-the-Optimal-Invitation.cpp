#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
long long count;


int median(int a[50005], int m)
{
	int mid;
	int mid1;
	int mid2;
	int ans1;
	int ans2;
	int sum;
	int ans;
	sum = 0;

	if(count % 2) {
		mid = count / 2 + 1;
		sum = 0;

		for (int i = 1; i <= m; i++) {
			if(a[i] + sum >= mid) {
				ans = i;
				break;
			}

			else {
				sum += a[i];
			}

		}

		return ans;
	}

	else {
	
		sum = 0;

		mid1 = count / 2;
		mid2 = count / 2 + 1;
		
		for (int i = 1; i <= m; i++) {
			if(a[i] + sum >= mid1) {
				ans1 = i;

				if(a[i] + sum >= mid2) {
					ans2 = i;
					break;
				}

				sum += a[i];

			}
			else {
				sum += a[i];
			}
		}

		return (ans1 + ans2) / 2;

	}


}




int main()
{
	int t;
	int x;
	int y;
	int k;
	int q;
	int m;
	int n;
	long long sumx;
	long long sumy;
	int ansx;
	int ansy;
	int a[50005];
	int b[50005];
	
	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &m);
		scanf("%d", &n);
		scanf("%d", &q);
		memset(a, 0, sizeof a);	
		memset(b, 0, sizeof b);	
		count = 0;
		
		for (int i = 0; i < q; i++) {
			scanf("%d", &x);
			scanf("%d", &y);
			scanf("%d", &k);
			a[x] += k;
			b[y] += k;
			count += k;
		}

		printf("Case %d: %d %d\n", cs, median(a,m), median(b, n));


	}

}




