#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
#define gama 0.57721566490
double a[1000005];

int main()
{

	int t;
	double ans;
	double ans2;
	int x;
	int n;
	double k;

	ans = 0;
	for (int i = 1; i <= 1000000; i++) {
		ans += 1.0 / i;
		a[i] = ans;

	}

	scanf("%d", &t);


	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &x);
		if(x <= 1000000) {

			printf("Case %d: %.9lf\n", cs, a[x]);
		}

		else {
			k = x + .5;
			ans2 = log(k) + gama;
			printf("Case %d: %.9lf\n", cs, ans2);
		}

	}

}


