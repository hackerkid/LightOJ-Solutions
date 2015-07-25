#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{

	int n;
	int t;
	int ans;


	int a[106];
	int b[106];

	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &n);
		ans = 0;

		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		
		for (int i = 0; i < n; i++) {
			scanf("%d", &b[i]);
		}

		for (int i = 0; i < n; i++) {
			ans = ans ^ (b[i] - a[i] - 1);
		}

		if(ans) {
			printf("Case %d: white wins\n", cs);
		}

		else {
			printf("Case %d: black wins\n", cs);

		}

	}

}

		

	
