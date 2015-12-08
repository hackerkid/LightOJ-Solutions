#include <bits/stdc++.h>
#define LIM 0.5
using namespace std;
int days;

double cal_prob(int people)
{
	double ans;
	double fin;

	int x;

	ans = 1;
	x = days;
		
	for (int i = 0; i < people; i++) {
		ans = ans * ((double)x / days);
		x--;
	}
	
	fin = 1 - ans;
	return fin;
}

int explore(int l, int r)
{
	int mid;
	mid = (l + r) / 2;

	if(cal_prob(mid) < LIM) {
		return explore(mid+1, r);
	}

	if(cal_prob(mid - 1) < LIM) {
		return mid;
	}

	return explore(l, mid-1);
}

int main()
{

	int t;
	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &days);
		//days = t;

		if(days == 1) {
			printf("Case %d: %d\n", cs, 1);
			continue;
		}
		
		if(days == 2) {
			printf("Case %d: %d\n", cs, 1);
			continue;
		}


		printf("Case %d: %d\n", cs, explore(1, 373) - 1);
	}

}
