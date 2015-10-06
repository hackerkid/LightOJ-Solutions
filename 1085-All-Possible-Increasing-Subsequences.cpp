#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define Last(i) ( (i) & (-i) )
#define MOD 1000000007
using namespace std;

int tree[100050];
int a[100050];
int n;
int cnt;


int update(int i, int val)
{

	while(i <= cnt) {
		tree[i] = (tree[i] + val) % MOD;
        i += Last(i);	}

}

int query(int i)
{
	int result;
	result = 0;

	while(i > 0) {
		result =  (result + tree[i]) % MOD;
        i -= Last(i);	}

	return result;

}

	
int main()
{

	int t;
	int result;
	int ans;
	
	
	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &n);
		cnt = 0;
		ans = 0;
		memset(a, 0, sizeof a);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}

		vector <int> b(a, a+n);

		memset(tree, 0, sizeof tree);

		map <int, int> m;

		sort(b.begin(), b.end());

		for (int i = 0; i < n; i++) {
			if(m.count(b[i]) == 0) {
				m[b[i]] = ++cnt;
			}
		}

		for (int i = 0; i < n; i++) {
			result = query(m[a[i]] - 1) + 1;
			ans = (result  + ans) % MOD;
			update(m[a[i]], result);
		}

		printf("Case %d: %d\n", cs, ans);




	}
		return 0;

}