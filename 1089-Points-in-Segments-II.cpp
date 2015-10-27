#include <iostream>
#include <stdio.h>
#include <map>
#include <utility>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
long long a[500000];
long long tree[500000];
long long cnt;



long long update(long long x, int val)
{	
	if(x == 0)
		return 0;
	while (x <= cnt) {
		tree[x] += val;
		x = x + (x & (-x)); 
	}

}

long long queryt(long long x)
{
	long long ans;
	ans = 0;

	while (x > 0) {
		ans += tree[x];
		x = x - (x & (-x));
	}

	return ans;

}



int main()
{	
	int t;
	long long x;
	long long y;
	int q;
	int n;

	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {

		map < long long, long long > mp;
		map <long long, long long > id;
		vector < pair <long long, long long> > v;
		vector < long long > query;
		
		memset(tree, 0, sizeof tree);

		cnt = 0;

		scanf("%d", &n);
		scanf("%d", &q);

		for (int i = 0; i < n; i++) {
			scanf("%lld", &x);
			scanf("%lld", &y);

			if(mp.count(x) == 0) {
				mp[x] = 1;
				a[cnt] = x;
				cnt++;
			}
			
			if(mp.count(y) == 0) {
				mp[y] = 1;
				a[cnt] = y;
				cnt++;
			}

			v.push_back(make_pair(x, y));

		}

		for (int i = 0; i < q; i++) {
			scanf("%lld", &x);
			query.push_back(x);

			if(mp.count(x) == 0) {
				mp[x] = 1;
				a[cnt] = x;
				cnt++;
			}
		}

		sort(a, a + cnt);

		for (int i = 0; i < cnt; i++) {
			id[a[i]] = i+1;
		}

		for (int i = 0; i < v.size(); i++) {
			x = v[i].first;
			y = v[i].second;

			x = id[x];
			y = id[y];

			update(x, 1);
			update(y + 1, -1);

		
		}

		printf("Case %d:\n", cs);

		

		for (int i = 0; i < query.size(); i++) {
			x = query[i];
			x = id[x];
			printf("%lld\n", queryt(x) );
		}

	}


}
