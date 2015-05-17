#include <stdio.h>
#include <string.h>

int main()
{
	int t;
	bool a[40];
	bool b[40];
	long long x;
	long long ans;
	int n;
	int ones;
	long long mul;
	int i;
	int j;
	scanf("%d", &t);

	for (int cases = 1; cases <= t; cases++) {
		scanf("%lld", &x);
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		n = 0;
		ones = 0;
		ans = 0;
		mul = 1;

		while(x) {
			if(x % 2 == 0) {
				a[n] = 0;
			}

			else {
				a[n] = 1;
			}

			n++;
			x = x / 2;

		}

		i = 0; 
		j = 1;

		while(1) {
			if(a[i] == 1 and a[j] == 0) {
				break;
			}
			if(a[i] == 1)
				ones++;
			i++;
			j++;

		}

		for (int k = 0; k < ones; k++) {
			b[k] = 1;
		}

		b[j] = 1;

		for (int k = j + 1; k <= n+1; k++) {
			b[k] = a[k];
		}

		for (int i = 0; i <= n + 1; i++, mul = mul * 2) {
			ans += b[i] * mul;
		}
/*
		for (int i = n + 2; i >= 0; i--) {
			cout << a[i] ;
		}

		cout << endl;
		
		for (int i = n + 2; i >= 0; i--) {
			cout << b[i] ;
		}

		cout << endl;
*/
		printf("Case %d: %lld\n", cases, ans);
	}

}

		






