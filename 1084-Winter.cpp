#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

long long a[100005];
bool vis[100005];
int n;
long long k;


int bfs()
{

	pair <int, int> temp;
	temp.first = 0;
	temp.second = 0;

	queue < pair <int, int> > q;

	q.push(temp);
	vis[0] = 1;

	while(!q.empty()) {
		int i = q.front().first;
		int count = q.front().second;

		q.pop();

		
		int j = i;
		int p;

		p = 0;

		if(j == n) {
			return count;
		}

		while((a[j] - a[i]) <= 2 * k and j < n) {
			j++;
			p++;
		}

		int k;
		k = 0;

		while((p - k) >= 3) {
			if(vis[j - k] == 0) {
				q.push(make_pair(j - k, count + 1));
				vis[j-k] = 1;
			}
			k++;
		}



	}

	return -1;


}
int main()
{
	int t;
	
	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &n);
		scanf("%lld", &k);
		
		memset(vis, 0, sizeof vis);

		for (int i = 0; i < n; i++) {
			scanf("%lld", &a[i]);
		}

		sort(a, a +  n);
		
		printf("Case %d: %d\n", cs, bfs());
		

	}

}


			




