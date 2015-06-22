#include <iostream>
#include <stdio.h>
#include <map>
#include <string.h>
using namespace std;

double p[110];
int million[110];
int n;
long long count;
double tol;

int main()
{

	int t;
	int sum;
	int ans;
	double val[10005];

	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%lf", &tol);
		scanf("%d", &n);
		sum = 0;

		for (int i = 0; i < n; i++) {
			scanf("%d", &million[i]);
			scanf("%lf", &p[i]);
			sum += million[i];
		}

		for (int i = 1; i <= sum; i++) {
			val[i] = 1;
		}

		val[0] = 0;
		int index;

		for (int j = 0; j < n; j++) {
			for(int i = sum; i >= 1; i--) {
				
				index = i - million[j];
				if(index >= 0) {
					val[i] = min(val[i], val[index] + (1 - val[index]) * p[j]);
				}

			}

		}

		for (int i = 0; i <= sum; i++) {
			if(val[i] < tol) {
				ans = i;
			}

		}

		printf("Case %d: %d\n", cs, ans);

	}

}



