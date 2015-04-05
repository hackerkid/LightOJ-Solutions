#include <vector>
#include <stdio.h>
#define sroot 1000007
#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
vector <int> primes;


int sieve()
{
	bool a[sroot];
	memset(a, 0, sizeof(a));

	for(int i = 2; i <= sroot; i++) {
		if(a[i] == 0) {
			for (int j = i + i; j <= sroot; j = j + i) {
				a[j] = 1;
			}

		}

	}

	for (int i = 2; i <= sroot; i++) {
		if(a[i] == 0) {
			primes.push_back(i);
		}

	}

	sort(primes.begin(), primes.end());

}




int main()
{
	sieve();

	int t;
	long long x;
	long long sum;
	long long k;
	long long temp;
	long long n;

	scanf("%d", &t);

	for (int cases = 1; cases <= t; cases++) {
		scanf("%lld", &x);
		sum = 1;
		n = sqrt(x);
		
		for(int i = 0; i <= primes.size() - 1 and primes[i] <= n ; i++) {
			
			k = 0;
			if(x < primes[i]) {
				break;
			}

			while(x % primes[i] == 0) {
				
				x = x / primes[i];
				k++;
			}

			sum = sum * (k + 1);

		}
		
		if(x > 1) sum *= 2;
		cout << x << endl;
		sum = sum - 1;

		printf("Case %d: %lld\n",cases, sum);

	}


}

