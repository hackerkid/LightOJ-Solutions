#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{

	int t;
	long long n;
	char x[6];

	scanf("%d", &t);

	for (int j = 1; j <= t; j++) {
		scanf("%lld", &n);
		scanf("%s", x);

		n = n % 3;
		if(strcmp(x, "Alice") == 0) {
			if(n == 0 or n == 2) {
				printf("Case %d: Alice\n", j);
			}

			else {
				printf("Case %d: Bob\n", j);
			}

		}

		else
		{
			if(n == 1 or n == 2) {
				printf("Case %d: Bob\n", j);
			}

			else {
				printf("Case %d: Alice\n", j);

			}

		}


	}



}


	
