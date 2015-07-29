#include <stdio.h>

int main()
{

	int t;

	scanf("%d", &t);

	int n;
	int count;

	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &n);
		count = 0;
		while(n) {
			count += n % 2;
			n = n / 2;
		}

		if(count % 2) {
			printf("case %d: odd\n", cs);
		}

		else {
			printf("case %d: even\n", cs);

		}

	}


}


