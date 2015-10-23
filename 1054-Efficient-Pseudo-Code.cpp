#include <iostream>
#include <stdio.h>
#include <vector>
#define sz 1000000
using namespace std;

vector <int> pr;

int sv[1000005];

long long MOD = 1000000007;
long long mod = 1000000007;
void extEuclid(int a, int b, int &x, int &y, int &gcd) {
    x = 0; y = 1; gcd = b;
    int m, n, q, r;
    for (int u=1, v=0; a != 0; gcd=a, a=r) {
        q = gcd / a; r = gcd % a;
        m = x-u*q; n = y-v*q;
        x=u; y=v; u=m; v=n;
    }
}
 
long long modInv(long long n, long long m) {
    int x, y, gcd;
    extEuclid(n, m, x, y, gcd);
    if (gcd == 1) return x % m;
        return 0;
}

long long mod_pow(long long x, long long y)
{

	long long ans;

	ans = 1;
	while(y) {
		if(y & 1) {
			ans = (ans * x) % MOD;

		}

		x = (x * x) % MOD;
		y = y >> 1;
	}

	return ans;


}
int main()
{
	pr.push_back(2);

	for (int i = 3; i * i <= sz; i += 2) {
		if(!sv[i]) {
			for (int j = i * i; j <= sz; j += 2 * i) {
				sv[j] = 1;
			}
		}
	}

	for (int i = 3; i <= sz; i += 2) {
		if(!sv[i]) {
			pr.push_back(i);
		}
	}
	int t;
	int n;
	int m;
	int k;
	long long ans;

	scanf("%d", &t);
	
	for (int cs = 1; cs <= t; cs++) {
		scanf("%d %d", &n, &m);
		vector < pair < int, int> > fact;
		
		for (int i = 0; i < pr.size() and pr[i] * pr[i] <= n ; i++) {
			k = 0;
			while(n % pr[i] == 0) {
				k++;
				n = n / pr[i];
			}

			if(k != 0) {
				fact.push_back(make_pair(pr[i], k));
			}
		}

		
		if(n != 1) {
			fact.push_back(make_pair(n, 1));
		}

		ans = 1;
		long long p;
		long long e;

		

		for (int i = 0; i < fact.size(); i++) {
			p = fact[i].first;
			e = fact[i].second;
			 ans = (ans * (mod_pow(p, e * m + 1LL) - 1LL + mod)) % mod;
   			 ans = (ans * mod_pow(p - 1LL, mod - 2)) % mod;
			
		}

		printf("Case %d: %lld\n", cs , ans);

	}

}

