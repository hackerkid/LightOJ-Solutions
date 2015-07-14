#include <iostream>
#include <stdio.h>
using namespace std;


bool between(int z, int x, int y)
{
	if(x > y) {
		swap(x, y);
	}

	return z >= x and z <= y;

}
int main()
{

	int x1;
	int x2;
	int y1;
	int y2;
	int n;
	int x;
	int y;

	int t;

	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &x1);
		scanf("%d", &y1);
		scanf("%d", &x2);
		scanf("%d", &y2);

		scanf("%d", &n);
		printf("Case %d:\n", cs);
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			scanf("%d", &y);

			if(between(x, x1, x2) and between(y, y1, y2)) {
					printf("Yes\n");
			}

			else {
				printf("No\n");
			}


		}



	}


}



