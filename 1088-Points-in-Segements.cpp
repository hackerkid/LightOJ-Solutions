#include <iostream>
#include <stdio.h>
using namespace std;
int a[100008];
int n;
int q;
int binary_left(int left, int right, int x)
{	
	int mid;

	mid = (left + right) / 2;

	if((mid+1 == n ||a[mid+1] > x) and (mid == 0 || a[mid-1] < x)) {
		if(a[mid] < x) {
			mid++;

		}
		return mid;
	}

	if(left > right) {
		return -9999;
	}

	if(a[mid] < x) {
		binary_left(mid +1, right, x);
	}

	else {
		binary_left(left, mid - 1, x);
	}

}


int binary_right(int left, int right, int x)
{	
	int mid;

	mid = (left + right) / 2;

	if((mid+1 == n ||a[mid+1] > x) and (mid == 0 || a[mid-1] < x)) {
		
		if(a[mid] > x) {
			mid--;
		}
		return mid;
	}

	if(left > right) {
		return -1;
	}

	if(a[mid] < x) {
		binary_right(mid +1, right, x);
	}

	else {
		binary_right(left, mid - 1, x);
	}

}

int main()
{

	int t;
	int left;
	int right;

	int x;
	int y;
	int ans;

	scanf("%d", &t);
	
	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &n);
		scanf("%d", &q);

		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		printf("Case %d:\n", cs);
		
		for (int i = 0; i < q; i++) {
			scanf("%d", &x);
			scanf("%d", &y);

			left = binary_left(0, n-1, x);
			right = binary_right(0, n-1, y);
				
			ans = right - left + 1;

			printf("%d\n",ans);

		}

	}

}


