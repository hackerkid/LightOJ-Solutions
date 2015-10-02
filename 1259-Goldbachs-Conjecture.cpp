#include <iostream>
#include <vector>
#include <stdio.h>
#define SIZE 10000000
using namespace std;

bool a[SIZE + 2];
int main()
{

	vector <int> prime;
	int t;
	int x;
	int y;
	int n;
	int count;
	
	a[0] = true;
	a[1] = true;

	for (int i = 2; i <= SIZE; i++) {
		if(a[i] == false) {
			prime.push_back(i);
			for (int j = 2 * i; j <= SIZE; j = j + i) {
				a[j] = true;
			}
		}
	}

	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &n);
		count = 0;

		for (int i = 0; true; i++) {
			x = prime[i];
			y = n - x;
			if(x > y) {
				break;
			}

			if(a[y] == 0) {
				count++;
			}

		}

		printf("Case %d: %d\n", cs, count);

	}


}
			
