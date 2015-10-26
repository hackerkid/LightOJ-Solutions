#include <iostream>
#include <stdio.h>
#define sz 100006
using namespace std;
long long dis[sz];
int n;

bool ok(long long k)
{
	
	for (int i = 1; i <= n; i++) {
		if(dis[i] - dis[i-1] == k) {
			k--;
		}

		else {
			if(dis[i] - dis[i-1] > k) {
				return 0;
			}
		}

	}

	if(k >= 0) {
		return 1;
	}

	else {
		return 0;
	}

}


int main()
{

	int t;
	long long k;
	int count;
	
	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &n);
		
		dis[0] = 0;

		for (int i = 1; i <= n; i++) {
			scanf("%lld", dis + i);
		}

		k = -1;

		for (int i = 1; i <= n; i++) {
			if((dis[i] - dis[i-1]) > k) {
				k = dis[i] - dis[i-1];
				count = 1;
			}

			else {
			
				if((dis[i] - dis[i-1]) == k) {
					k = dis[i] - dis[i-1];
					count++;
				}
			}

		}


		if(count > 1) {
			printf("Case %d: %lld\n", cs, k + 1);
		}
		
		else {
			if(ok(k)) {
				printf("Case %d: %lld\n", cs, k);
			}

			else {
				printf("Case %d: %lld\n", cs, k+1);
			}
		}
	}
}


	


		
		


