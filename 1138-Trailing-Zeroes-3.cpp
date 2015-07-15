#include <iostream>
#include <stdio.h>
#include <string.h>
#include <limits.h>

using namespace std;
int q;
int n;


inline int zeros(int n) {
	int ret = 0;
	while(n > 0) {
		n /= 5;
		ret += n;
	}
	
	return ret;
}

int explore(int start, int end)
{
	int mid;
	int count;
	int t;

	if(start > end) {
		return -1;
	}

	mid = (start + end) / 2;

	count = zeros(mid);
	
	if(count == n) {
		
		while(zeros(mid) == n) {
			mid--;
		}
		return ++mid;
	}

	if(count < n) {
		return explore(mid+1, end);
	}

	else {
		return explore(start, mid-1);
	}

}






int main()
{

	int t;
	int ans;
	
	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &n);
		ans = explore(1, INT_MAX);
		if(ans != -1) {
			printf("Case %d: %d\n", cs, ans);
		}
		else {
			printf("Case %d: impossible\n", cs);
		}
	}


}






