#include <iostream>
#include <stdio.h>
using namespace std;
long long n;
long long nn;
long long a[1000005];

long long cal(long long i)
{	long long ans;

	ans =  ((i - 1) * (nn - (i - 1)) + (nn - (i - 1)));

	// cout << " value of i is " << i << " " << ans << endl;

	return ans;

}
int main()
{


	long long t;
	long long q;
	long long x;
	long long ch;
	long long sum;
	long long v;
	long long temp;


	scanf("%lld", &t);

	for (long long cs = 1; cs <= t; cs++) {
		scanf("%lld", &n);
		scanf("%lld", &q);
		sum = 0;
		nn = n - 1;
		for (long long i = 0; i < n; i++) {
			scanf("%lld", a + i);
		}
	
		for (long long i = 1; i < n; i++) {
			x = a[i - 1] - a[i];
			sum = sum + cal(i) * x;
		}
		
		printf("Case %lld:\n", cs);
		for (long long i = 0; i < q; i++) {
			scanf("%lld", &ch);
			if(ch) {
				printf("%lld\n", sum);
			}

			else {
				scanf("%lld", &x);
				scanf("%lld", &v);
				temp = 0;

				if(x != 0) {
					temp = cal(x) * (a[x-1] - a[x]);
					// cout << "x is " << x << " a[x] " << a[x] << "a[x-1]" << a[x-1] << endl;
				}

				if(x != n -1) {
					temp += cal(x+1) * (a[x] - a[x+1]);
				}
				long long epic;
				epic = temp;
				sum -= temp;

				a[x] = v;
				
				temp = 0;

				if(x != 0) {
					temp = cal(x) * (a[x-1] - a[x]);
				}

				if(x != n -1) {
					temp += cal(x+1) * (a[x] - a[x+1]);
				}
				// cout<< "sum removed is " << epic  << " | sum added " << temp << endl;
				
				sum += temp;

			}

			for (long long i = 0; i < n; i++) {
				// cout << a[i] << " ";
			}
			// cout << endl;

		}

	}

}





