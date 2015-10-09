#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int a[2000005];
int tree[2000005];
int vis[2000005];
int n;


int update(int i, int val)
{
	
	while(i <= n) {
		tree[i] += val;
		i = i + (i & (-i));
	}

}

long long query(int i)
{

	long long res = 0;

	while(i > 0) {
		res = res + tree[i];
		i = i - (i & (-i));
	}

	return res;

}
	

int search(int i, int j, int x)
{
	int mid;
	int val;
	mid = (i + j) / 2;

	if(i > j ) {
		return -1;
	}
	
	val = query(mid);
//	cout <<"mid => " <<mid << "val => " <<  val << "x = > " << x << endl;

	if(val > x) {
		return search(i, mid-1, x);
	}

	if(val < x) {
		return search(mid+1, j, x);
	}

	if(val == x) {
		if(vis[mid] == 1) {
			return mid;
		}

		else {
			return search(i, mid-1, x);
		}

	}


}
			

int main()
{

	int t;
	int m;
	int count;
	char ch;
	int x;
	int k;
	int nn;


	scanf("%d", &t);
	n = 100000;

	for (int cs = 1; cs <= t;cs++) {
		scanf("%d %d", &nn, &m);
		n = nn + m + 1;

		count = 0;

		memset(a, 0, sizeof a);
		memset(tree, 0, sizeof tree);
		memset(vis, 0, sizeof vis);
		
		printf("Case %d:\n", cs);
		for (int i = 1; i <= nn; i++) {
			scanf("%d", a + i);
			vis[i] = 1;
			count++;
			update(i, 1);
		}


		for (int i = 0; i < m; i++) {
			getchar();
			scanf("%c %d", &ch, &x);
			
			//cout << ch << " " << x << endl;
			
			if(ch == 'a') {
				nn++;
				a[nn] = x;
				vis[nn] = 1;
				update(nn, 1);
				count++;
			}

			if(ch == 'c') {
				if(x > count) {
					printf("none\n");
					continue;
				}

				k = search(1, nn, x);

				update(k, -1);
				vis[k] = 0;
				count--;
				printf("%d\n", a[k]);
			}
			/*
			for (int i = 1; i <= nn; i++) {
				cout << query(i) << " ";
			}
			cout << endl;
			
			for (int i = 1; i <= nn; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
			for (int i = 1; i <= nn; i++) {
				cout << vis[i] << " ";
			}

			cout << endl;
			*/
		}

	}

}


