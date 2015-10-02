#include <iostream>
#define SIZE 100005
#include <string.h>
#include <stdio.h>

using namespace std;
int a[SIZE];
int n;


long long update(int i, int val)
{

	while(i <= n) {
		a[i] = a[i] + val;
		i = i + (i & (-i));
	}

}

long long query(int i)
{	
	long long ans;
	ans = 0;

	while(i > 0) {
		ans = ans + a[i];
		i = i - (i & (-i));
	}

	return ans;
}

int main()
{
	int t;
	int x;
	int y;
	int w;
	int choice;
	long long ans;
	int q;
	int ch;

	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &n);
		scanf("%d", &q);
		
		memset(a, 0, sizeof a);

		for (int i = 1; i <= n; i++) {
			scanf("%d", &x);
			update(i, x);
		}



		printf("Case %d:\n", cs);
		for (int i = 0; i < q; i++) {
			scanf("%d", &ch);
			
			switch(ch) {
				case 1:
					scanf("%d", &x);
					x++;
					ans = query(x) - query(x-1);
					update(x, -ans);
					printf("%lld\n", ans);
					break;
				case 2:
					scanf("%d", &x);
					x++;
					scanf("%d", &w);
					update(x, w);
					break;

				case 3:
					scanf("%d", &x);
					scanf("%d", &y);
					x++;
					y++;
					ans = query(y) - query(x -1);
					printf("%lld\n", ans);
					break;

			}
		}
	}
}





