#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int a[100];
int n;
int k;

long long ans[40][40];

int ok(int x, int y)
{

	for (int i = 0; i < x; i++) {
		
		if(a[i] == y) {
			return 0;
		}

	}


	return 1;

}

long long explore(int i, int count)
{

	long long x;
	long long y;
	long long sum = 0;


	if(i == n) {
		if(count == k) {
			return 1;
		}

		else {
			return 0;
		}

	}
	if(ans[i][count] != -1) {
		return ans[i][count];
	}

	for (int j = 0; j < n; j++) {
		
		y = 0;
		x = 0;		
		if(ok(i, j)) {
			a[i] = j;
			x = explore(i+1, count+1);
		}

		sum += x;

	}

	a[i] = -1;
	y = explore(i+1, count);

	sum += y;
	ans[i][count] = sum;
	return sum;



}


int main()
{

	int t;
	
	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &n);
		scanf("%d", &k);

		memset(a, -1, sizeof(a));
		memset(ans, -1, sizeof(ans));

		printf("Case %d: %lld\n",cs, explore(0, 0));

	}


}

