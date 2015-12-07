#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{

	int ax;
	int ay;
	int bx;
	int by;
	int cx;
	int cy;
	int dx;
	int dy;

	long long area;
	long long area1;
	long long area2;

	int t;

	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		
		scanf("%d %d %d %d %d %d",&ax, &ay, &bx, &by, &cx, &cy);
		
		dx = ax + cx - bx;
		dy = ay + cy - by;

		area1 = ax * by + bx * cy + cx * dy + dx * ay;
		area2 = ay * bx + by * cx + cy * dx + dy * ax;
		
		area = abs(area1 - area2);
		area = area / 2;

		printf("Case %d: %d %d %lld\n",cs,dx, dy, area);
	}

}


