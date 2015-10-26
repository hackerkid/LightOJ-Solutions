#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{

	char a[110];
	int n;
	int count;
	bool mark[110];
	int t;

	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &n);
		count = 0;

		scanf("%s", a);
		
		memset(mark, 0, sizeof mark);

		for (int i = 0; i < n; i++) {
			if(a[i] == '.' and !mark[i]) {
				if(i + 1 < n) {
					mark[i+1] = 1;
				}

				if(i + 2 < n) {
					mark[i+2] = 1;
				}

				count++;
			}
		}

		printf("Case %d: %d\n", cs, count);
	}

}
		
