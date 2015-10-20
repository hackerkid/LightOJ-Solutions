#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{

	double v1;
	double v2;
	double a1;
	double a2;
	double v3;
	int  t;
	double tim;
	double ans;
	double dis;
	double tim1;
	double tim2;
	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%lf", &v1);
		scanf("%lf", &v2);
		scanf("%lf", &v3);
		scanf("%lf", &a1);
		scanf("%lf", &a2);

		tim1 = v1 / a1;
		tim2 = v2 / a2;

		tim = max(tim1, tim2);


		ans = tim * v3;
		dis = v1 * tim1 + 0.5 * -a1 * tim1 * tim1;
		dis += v2 * tim2 + 0.5 * -a2 * tim2 * tim2;

		printf("Case %d: %.9lf %.9lf\n",cs,dis, ans);

	}

	return 0;

}


