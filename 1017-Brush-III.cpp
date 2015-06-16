#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

int n;
int k;
int w;
int ans[110][110][110];

struct node
{
	int  val;
	int count;
};


node a[200];

bool epic(node x, node y)
{
	if(x.val < y.val) {
		return 1;
	}

	return 0;
}


int explore(int start, int end, int count)
{
	
	
	if(end == n) {
		return 0;
	}

	if(count == k) {
		return 0;
	}

	if(ans[start][end][count] != -1) {
		return ans[start][end][count];
	}

	if(a[end].val - a[start].val <= w) {
		if(start == end) {

			return ans[start][end][count] = max(a[end].count + explore(start, end+1, count), explore(end+1, end+1, count));
		}

		else {
			return ans[start][end][count] = a[end].count +  explore(start, end+1, count);
		}
	}

	else {
		return ans[start][end][count] =  explore(end, end, count + 1);
	}

}


int main()
{
	int t;
	int x;
	int y;
	int tot;
	
	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		
		scanf("%d", &tot);
		scanf("%d", &w);
		scanf("%d", &k);
		
		map <int, int> q;
		memset(ans, -1, sizeof(ans));
		n = 0;

		for (int i = 0; i < tot; i++) {
			scanf("%d", &x);
			scanf("%d", &y);

			if(q.count(y) == 0) {
				node temp;
				temp.val = y;
				temp.count = 1;
				q[y] = n;
				a[n] = temp;
				n++;
			}

			else {
				a[q[y]].count++;
			}


		}


		sort(a, a + n, epic);
		printf("Case %d: %d\n", cs,explore(0, 0, 0)); 
		

	}

}


