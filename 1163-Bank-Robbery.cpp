#include <iostream>
#include <stdio.h>
using namespace std;

int a[1000008];

unsigned long long calculate(unsigned long long y, int cs)
{

	unsigned long long x;
	unsigned long long z;
	unsigned long long w;

	x = (10 * y) / 9;

	x--;
	
	printf("Case %d:", cs);
	
	if(x - (x / 10) == y) {
		printf(" %lld", x);
	}

	x++;


	if(x - (x / 10) == y) {
		printf(" %lld", x);
	}

	x++;


	if(x - (x / 10) == y) {
		printf(" %lld", x);
	}
		
	printf("\n");
}

int main()
{

	int t;
	unsigned long long x;
	unsigned long long y;

	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%lld", &y);
		calculate(y, cs);
	}



}

	

