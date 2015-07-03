#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;

int m;
int n;
int a[12];
long long ans[12][11];
long long getCount(int i, int x)
{
	long long count;
	
	count = 0;
	
	if(ans[i][x] != -1) {
		return ans[i][x];
	}
	
	if(i == n) {
		return 1;
	}



	for (int j = 0; j < m; j++) {
		if(x == 0 or (abs(a[j] - x) <= 2)) {
			count += getCount(i+1, a[j]);
		}

	}
	ans[i][x] = count;
	return count;

}




int main()
{

	int t;
	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		memset(ans, -1, sizeof(ans));

		scanf("%d", &m);
		scanf("%d", &n);

		for (int i = 0; i < m; i++) {
			scanf("%d", &a[i]);
		}

		printf("Case %d: %lld\n",cs, getCount(0, 0));

	}


}



