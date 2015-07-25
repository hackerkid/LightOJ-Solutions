#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

struct node{
	int l;
	int r;
	int i;
};

int ans;
struct node q[50005];
int a[100007];
int mod;
int counts[100007];
int fin[50007];

bool cmp(node x, node y)
{
	if((x.l) / mod == (y.l / mod)) {
		return x.r < y.r;
	}

	return x.l / mod < y.l / mod;

}


int update(int l)
{	
	counts[a[l]]++;


	
	if(counts[a[l]] == 1) {
		ans++;
	}

}

int remove(int l)
{
	
	counts[a[l]]--;
	
	if(counts[a[l]] == 0) {
		ans--;
	}

}
int main()
{

	int t;
	int n;
	int m;
	int x;
	int y;
	
	scanf("%d", &t);
	for (int cs = 1; cs <= t; cs++) {
		scanf("%d",&n);
		scanf("%d",&m);
		mod = sqrt(n);

		for (int i = 0; i < n; i++) {
			scanf("%d", a + i);
		}

		for (int i = 0; i < m; i++) {
			scanf("%d", &x);
			scanf("%d", &y);
			x--;
			y--;
			q[i].l = x;
			q[i].r = y;
			q[i].i = i;
		}

		sort(q, q + m, cmp);
		ans = 0;
		
		int currentL;
		int currentR;

		currentL = 0;
		currentR = 0;

		memset(counts, 0, sizeof(counts));

		for (int i = 0; i < m; i++) {
			x = q[i].l;
			y = q[i].r;

			while(currentL < x) {
				remove(currentL);
				currentL++;
			}


			while(currentL > x) {
				update(currentL - 1);
				currentL--;
			}

			while(currentR <= y) {
				update(currentR);
				currentR++;
			}

			while(currentR > y+1) {
				remove(currentR - 1);
				currentR--;
			}
			
			fin[q[i].i] = ans;

		}

		printf("Case %d:\n", cs);
		for (int i = 0; i < m; i++) {
			printf("%d\n", fin[i]);
		}


		

	}


}

