#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{

	int t;
	int last;
	int a[100];
	int ans;
	int lies;
	int n;
	int diff;

	scanf("%d", &t);
	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++ ) {
			scanf("%d", a + i);
		}

		last = 2;
		ans = 0;

		for (int i = 0; i < n; i++) {
			diff = a[i] - last;
			if(diff) {
				lies = ceil((float) diff /  5.0);
				if(lies == 0)
					ans++;
				else 
					ans += lies;

				last = a[i];
			}
		}

		printf("Case %d: %d\n", cs, ans);
	}
}