#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;


int create_tree(int input[],int tree[], int n)
{	
	int x;

	for (int i = 1; i <= n; i++) {
		x = i;

		while(x <= n) {
			tree[x] += input[i];
			x += x & -x;
		}
	}
}


int update(int tree[], int x, int val, int n)
{	
	if(x == 0) {
		return 0;
	}

	while(x <= n) {
		tree[x] +=  val;
		x += x & -x;
	}
}

int query(int tree[], int x)
{	
	int sum;
	sum = 0;

	while(x > 0) {
		sum += tree[x];
		x -= x & -x;
	}

	return sum;
}

int alter(int tree[], int i, int j, int n)
{
	update(tree, i, 1, n);
	update(tree, j+1, -1, n);

}

int main()
{	
	int N = 100009;
	int a[N];
	int tree[N];
	int n;
	int x;
	int t;
	int y;
	char temp;
	int q;
	char choice;
	char epic[100007];
	int ans;

	ios_base::sync_with_stdio(false);



	cin >> t;

	for (int cs = 1; cs <= t; cs++) {
		
		cin >> epic;
		n = strlen(epic);
		for (int i = 0; i < n; i++) {
			a[i+1] = epic[i] - '0';
		}

//		create_tree(a, tree, n);
		memset(tree, 0, sizeof(tree));

		cin >> q;
		
		printf("Case %d:\n", cs);

		for (int i = 0; i < q; i++) {

			cin >> choice;
			switch(choice) {
				case 'I': 
					cin >> x;
					cin >> y;
					alter(tree, x, y, n);
					break;

				case 'Q': 
					cin >> x;
					ans = (a[x] ^ (query(tree, x) % 2));
					printf("%d\n", ans);
					break;
			}

		}

	}




}
