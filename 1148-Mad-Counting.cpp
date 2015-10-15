#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int a[1000005];

int main()
{

	int t;
	int x;
	int ans;
	int n;
	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		memset(a, 0, sizeof a);
		ans = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			x++;
			if(a[x] == 0) {
				ans += x;
				a[x] = 1;
				if(a[x] == x)
					a[x] = 0;
				continue;
			}
			
			if(a[x] < x) {
				a[x]++;
				if(a[x] == x) {
					a[x] = 0;
				}
			}


		}

		printf("Case %d: %d\n", cs, ans);
	}

	return 0;

}


