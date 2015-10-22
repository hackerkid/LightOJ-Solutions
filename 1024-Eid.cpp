#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#define sz 10000

using namespace std;
int sv[sz];



    string multiply( string a, long long b ) {
        // a contains the biginteger in reversed form
        int carry = 0;
        for( int i = 0; i < a.size(); i++ ) {
            carry += (a[i] - 48) * b;
            a[i] = ( carry % 10 + 48 );
            carry /= 10;
        }
        while( carry ) {
            a += ( carry % 10 + 48 );
            carry /= 10;
        }
        return a;
    }


int main() {
	vector <int> prime;
	prime.push_back(2);

	for (int i = 3; i * i <= sz; i++) {
		if(sv[i] == 0) {
			for (int j = i * i; j <= sz; j += 2 * i) {
				sv[j] = 1;
			}
		}
	}

	for (int i = 3; i <= sz; i += 2) {
		if(sv[i] == 0) {
			prime.push_back(i);
		}
	}

	int t;
	long long x;
	long long mul;
	int n;
	string lcm;
	
	string temp;
	
	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		long long fact[10000];
		memset(fact, 0, sizeof fact);
		scanf("%d", &n);
		lcm = "1";

		for(int j = 0; j < n; j++) {
			
			scanf("%lld", &x);			
			// cout << "=== " << x << endl;
			for (int i = 0; i < prime.size() and prime[i] * prime[i] <= x ; i++) {
				mul = prime[i];
				while(x % prime[i] == 0) {
					// cout << mul << "inside \n";
					mul = mul * prime[i];
					x = x / prime[i];
				}

				mul = mul / prime[i];

				fact[i] = max(fact[i], mul);
			}

			// cout <<"remains "<< x << endl;

			int k;
			if(x == 2 or ((x % 2) and sv[x] == 0)) {
				// cout << "inside " << x << endl;
				k = lower_bound(prime.begin(), prime.end(),x) - prime.begin();
				fact[k] = max(fact[k], x);

			}

		}

		for (int i = 0; i < prime.size(); i++) {
			if(fact[i] != 0) {
				lcm = multiply(lcm, fact[i]);
			}

		}

		char ans[1000000];
		string s;
		s = lcm;

		for (int i = 0, j = s.size() - 1; i < s.size(); i++, j--) {
			ans[i] = s[j];
		}

		ans[s.size()] = '\0';

		printf("Case %d: %s\n", cs, ans);
	}

}
