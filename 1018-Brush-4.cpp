#include <iostream>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#define set(x, i) (x | (1 << i))
#define check(x, i) (x & (1 << i))
using namespace std;

enum CONST {N = 16};

typedef struct node {
	int x;
	int y;
} node;

int n;
int collinear[N+3][N+3];
int dp[1 << N+2];

node a[N + 5];

int cal(int state)
{
	int count;
	count = 0;

	for (int i = 1; i <= n; i++)
		if(check(state, i))
			count++;

	return count;
}

int explore(int status)
{
	int count;
	int temp;
	int mini;

	mini = INT_MAX;

	if(dp[status] != -1) {
		return dp[status];
	}
	count = cal(status);

	if(count == n-1) {
		return 1;
	}

	if(count == n) {
		return 0;
	}
	
	

	for (int i = 1; i <= n; i++) {
		if(check(status,i) == 0) {
			for (int j = i+1; j <= n; j++) {
				if(check(status, j) == 0) {
					temp = set(status, i);
					temp = set(temp, j);

					temp = temp | collinear[i][j];
					mini = min(mini, explore(temp));
				}
			}
			break;
		}

	}

	return dp[status] = 1 + mini;

}



bool is_collinear(int i, int j, int k)
{

	int x1;
	int y1;
	int x2;
	int y2;
	int x3;
	int y3;

	x1 = a[i].x;
	y1 = a[i].y;

	x2 = a[j].x;
	y2 = a[j].y;

	x3 = a[k].x;
	y3 = a[k].y;

	return (y2 - y1) * (x3 - x2) == (x2 - x1) * (y3 - y2);

}

void calculate_collinear_points()
{

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if(i != k and j != k and is_collinear(i, j, k)) {
					collinear[i][j] = set(collinear[i][j], k);
					collinear[j][i] = set(collinear[j][i], k);
				}
			}
		}
	}

}


int main()
{

	int t;
	node temp;

	scanf("%d", &t);

	for(int cs = 1; cs <= t; cs++) {
		scanf("%d", &n);
		
		memset(collinear, 0, sizeof collinear);
		memset(dp, -1, sizeof dp);

		for (int i = 1; i <= n; i++) {
			scanf("%d", &temp.x);
			scanf("%d", &temp.y);
			a[i] = temp;
		}

		calculate_collinear_points();

		printf("Case %d: %d\n", cs, explore(0));

	}

}
