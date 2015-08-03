#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;


long long fact_cal(int x)
{

	long long nplus1 = x;
	nplus1++;

	return (long long) (x * nplus1) / 2;

}

int main()
{

	int t;
	int n;
	int m;

	int a[500004];
	int count[500005];
	long long sum;

	scanf("%d", &t);


	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &n);
		scanf("%d", &m);

		memset(count, 0, sizeof(count));
		sum = 0;

		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		
		a[0] = a[0] % m;

		for (int i = 1; i < n; i++) {
			a[i] = (a[i-1] + a[i]) % m;
		}
		

		for (int i = 0; i < n; i++) {
			count[a[i]]++;
		}

		sum += count[0];

		long long temp;
		
		for (int i = 0; i <= 500000; i++) {
			sum = sum + fact_cal(count[i] -1);
		}

		printf("Case %d: %lld\n", cs, sum);

	}

}



		

