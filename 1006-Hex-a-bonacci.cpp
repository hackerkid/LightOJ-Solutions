#include <stdio.h>
#include <iostream>
using namespace std;
long long t;
long long a;
long long b;
long long c;
long long d;
long long e;
long long f;
long long n;
long long x[10005];

int fn( int n ) {
	for (int i = 0; i <= n; i++) {

    	if( i == 0 ) {
			x[i] = a;
			continue;
		}
	    if( i == 1 ) {
			x[i] = b;
			continue;
		}
    	if( i == 2 ) {
			x[i] = c;
			continue;
		}
	    if( i == 3 ) {
			x[i] = d;
			continue;
		}
    	if( i == 4 ) {
			x[i] = e;
			continue;
		}
	    if( i == 5 ) {
			x[i] = f;
			continue;
		}
    	x[i] = x[i-1] + x[i-2] + x[i-3] + x[i-4] + x[i-5] + x[i-6];
		x[i] = x[i] % 10000007;

	}

	return x[n];
}

int main()
{


	long long ans;

	
	cin >> t;

	for (long long i = 1; i <= t; i++) {
		cin >> a;
		cin >> b;
		cin >> c;
		cin >> d;
		cin >> e;
		cin >> f;
		cin >> n;

		ans = fn(n);
		ans = ans % 10000007;

		cout << "Case "<< i <<": "<< ans << endl;
	}


}

		

