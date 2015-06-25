#include <iostream>
#include <stdio.h>
#include <queue>
#include <limits.h>
#include <string.h>
using namespace std;

struct node{
	int i;
	int j;
	int count;
};

int n;
int k;
char a[20][20];
int temp;

node find_distance(char target, node start)
{

	queue <node> q;
	node temp;

	int b[4] = {+1, -1, 0, 0};
	int c[4] = {0, 0, +1, -1};
	int i;
	int j;
	int ii;
	int jj;
	int vis[20][20];
	
	memset(vis, 0, sizeof(vis));
	q.push(start);
	
	vis[start.i][start.j] = 1;

	while(!q.empty()) {
		temp = q.front();
		q.pop();

		i = temp.i;
		j = temp.j;

		if(a[i][j] == target) {
			return temp;
		}

		for (int cs = 0; cs < 4; cs++) {
			if((i + b[cs] < n and i + b[cs] >= 0) and (j + c[cs] < n and j + c[cs] >= 0)) {
				
				
				node epic;
				ii = i + b[cs];
				jj = j + c[cs];
				
				if((a[ii][jj] == '.' or a[ii][jj] == target) and vis[ii][jj] == 0) {
					epic.i = i + b[cs];
					epic.j = j + c[cs];
					epic.count = temp.count + 1;
					vis[ii][jj] = 1;
					q.push(epic);

				}
			}

		}


	}

	temp.count = INT_MAX;
	return temp;





}


		
		
		



int main()
{	
	
	int t;
	int sum;
	int starti;
	int startj;
	char target;

	scanf("%d", &t);
	
	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &n);
		k = -999;
		sum = 0;

		

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				temp = a[i][j] - 'A' + 1;
				k = max(k, temp);
				if(a[i][j] == 'A') {
					starti = i;
					startj = j;
				}
			}

		}

		node temp;
		temp.i = starti;
		temp.j = startj;
		temp.count = 0;
		
		int i;

		for (i = 0; i < k; i++) {
			target = 'A' + i;
			temp.count = 0;
			temp = find_distance(target, temp);

			if(temp.count == INT_MAX) {
				break;
			}

			a[temp.i][temp.j] = '.';

			sum += temp.count;

		}

		if(i == k) {
			printf("Case %d: %d\n", cs, sum);
		}

		else {
			printf("Case %d: Impossible\n", cs);

		}


	}


}
