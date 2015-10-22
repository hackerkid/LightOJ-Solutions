#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define sz 1000100
#define primecnt 78504


int sv[1000105];
int cnt[primecnt + 100];

vector <int> prime;


long long __lcm(long long a, long long b)
{
	long long ans;

	ans = a * b;
	ans = ans / __gcd(a, b);

	return ans;

}
int main()
{
	
	int t;
	long long a;
	long long b;
	long long lcm;
	long long c;
	long long temp;
	long long ans;
	long long mul;
	int ok;
	for (int i = 3; i * i <= sz; i += 2) {
		if(!sv[i]) {
			for (int j = i * i; j <= sz; j += 2 * i) {
				sv[j] = 1;
			}
		}
	}

	prime.push_back(2);
	for (int i = 3; i <= sz; i += 2) {
		if(sv[i] == 0) {
			//cout << i << endl;
			prime.push_back(i);
		}
	}

	//cout << prime.size() << endl;
	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%lld", &a);
		scanf("%lld", &b);
		scanf("%lld", &lcm);

		
		temp = 1;
		
		

		for (int i = 0; i < prime.size(); i++) {
			mul = prime[i];
			cnt[i] = 1;
			while(a % mul == 0 or b % mul == 0) {
				temp = temp * prime[i];
				cnt[i] = cnt[i] * prime[i];
				mul = mul * prime[i];
			}

			if(cnt[i] != 1) {
				//cout << prime[i] << " " << cnt[i] << endl;
			}
			
		}

		c = lcm / temp;

		ans = 1;

		
		if(c == 0) {
			printf("Case %d: impossible\n", cs);
			continue;
		}
		for (int i = 0; i < prime.size(); i++) {
			mul = prime[i];
			ok = 0;
			while(c % mul == 0) {
				cnt[i] = cnt[i] * prime[i];
				ok = 1;
				c = c / mul;

			}

			if(ok) {
				ans = ans * cnt[i];
			}
		}

		ans = ans * c;

		if(__lcm(a, __lcm(b, ans)) != lcm) {
			printf("Case %d: impossible\n", cs);
			continue;
		}

					
		printf("Case %d: %lld\n", cs, ans);


	}

}

