#include <iostream>
#include <stdio.h>
#include <utility>
#include <algorithm>
using namespace std;

pair <int, int> minify(pair <int, int> temp)
{
	int x;
	int y;
	int ok;
	x = temp.first;
	y = temp.second;

	ok = 1;

	while(ok) {
		ok = 0;
		for (int i = 2; i <= y; i++) {
			if(x % i == 0 and y % i == 0) {
				ok = 1;
				x = x / i;
				y = y / i;
			}

		}

	}


	temp.first = x;
	temp.second = y;

	return temp;

}


int main()
{

	int t;
	int psum;
	int nsum;
	int n;
	int ncount;
	int x;
	int y;
	
	pair <int, int> temp;
	scanf("%d", &t);

	for (int cases = 1; cases <= t; cases++) {
		scanf("%d", &n);
		nsum = 0;
		psum = 0;
		ncount = 0;
		for(int i = 0; i < n; i++) {
			scanf("%d", &x);
			if(x < 0) {
				ncount++;
				nsum += abs(x);
			}

			else {
				nsum += x;
			}

		}

		if(ncount == n) {
			printf("Case %d: inf\n", cases);
		}

		else {
			temp.first = nsum;
			temp.second = n - ncount;
			temp = minify(temp);

			printf("Case %d: %d/%d\n",cases, temp.first, temp.second);
		}

	}


}


