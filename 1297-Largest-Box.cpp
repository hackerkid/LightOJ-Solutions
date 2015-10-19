#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <math.h>
using namespace std;

double l;
double b;

double area(double x)
{
	return (l - 2 * x) * (b - 2 * x) * x;
}

int main()
{

	int t;
	double x1;
	double x2;
	double lpb;
	double ans;

	scanf("%d",&t); 

	for (int cs = 1; cs <= t; cs++) {
		scanf("%lf", &l);
		scanf("%lf", &b);
	
		lpb = l + b;
		x1 = (4 * lpb + sqrt(16 * lpb * lpb - 48 * l * b)) / 24.0;
		x2 = (4 * lpb - sqrt(16 * lpb * lpb - 48 * l * b)) / 24.0;
		
		ans = INT_MIN;
		
		if(x1 > 0) {
			ans = max(ans, area(x1));
		}

		if(x2 > 0) {
			ans = max(ans, area(x2));
		}

		printf("Case %d: %.9lf\n", cs, ans);


	}

}

