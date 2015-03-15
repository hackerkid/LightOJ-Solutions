#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include <utility>
#define check(n, pos) (n & (1<<pos))
#define set(n, pos) (n | (1<<pos))
using namespace std;

int n;
long long a[20][20];
int mm[17][1<<17];

long long wow(int i, long long vis)
{

	long long sum;
	sum = -1;

	if(i == n) {
		return 0;
	}

	if(mm[i][vis] == -1) {
		for (int j = 0; j < n; j++) {
			if(check(vis, j) == 0) {
				sum = max(sum, a[i][j] + wow(i+1, set(vis, j)));
			}

		}

		mm[i][vis] = sum;
		return sum;
	}


	else {
		return mm[i][vis];
	}

}
			



int main()
{

	int t;
	int x;
	long long sum;
	long long vis;
	vis = 0;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d", &n);

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				scanf("%lld", &a[j][k]);
			}

		}
		
		
		memset(mm, -1 , sizeof(mm));
		vis = 0;
		sum = wow(0, vis);
		printf("Case %d: %lld\n",i, sum);

	}
}
