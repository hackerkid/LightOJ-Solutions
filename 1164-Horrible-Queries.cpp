#include <iostream>
#include <stdio.h>
#include <string.h>
#define size 100009
using namespace std;

long long tree[4 * size];
long long a[size];
long long lazy[4 * size];



long long update(int a, int b, int i, int j, int node, int val)
{
	// cout << "->"<<a << " "<< b << " ";

	if(lazy[node]) {
		
		tree[node] += lazy[node] * ((b - a) + 1);
		
		if(a != b) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}

		lazy[node] = 0;

	}

	if(b < i or a > j) {
		// cout << " " << "0"<< endl;
		return 0;
	}


	if(a >= i and b <= j) {
		tree[node] += val * ((b - a) + 1);
		
		if(a != b) {
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}

		// cout << tree[node] << endl;
		
		return 0;
	}

	update(a, (a+b)/2, i, j, node * 2, val);
	update((a+b)/2 + 1,b, i, j, node * 2 + 1, val);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	// cout << tree[node] << endl;


}

long long query(int i, int j,int a, int b,int node)
{
	long long x;
	long long y;


	if(b < a or a > j or b < i) {
		// cout <<"invalid -> "<< i << " " << j << " ";

		// cout << " 0"<<endl;
		return 0;
	}
	
	if(lazy[node]) {
		// cout <<i << " "<< j << " is lazy with "<< lazy[node] << endl;
		tree[node] += lazy[node]  * ((j - i) + 1);
		if(i != j) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];

		}

		lazy[node] = 0;
	}
	
	if(i >= a and j  <= b) {
		// cout <<" perfect fit -> "<< i << " " << j << " ";

		// cout << tree[node] << endl;
		return tree[node];
	}

	x = query(i, (i+j)/2,a,b, node * 2);
	y = query((i+j)/2+1, j,a, b,node * 2 + 1);
		// cout <<"end-> "<< i << " " << j << " ";

	// cout << x + y << endl;

	return x + y;

}






	

long long create_tree(int i, int j, int node)
{
	
	long long x;
	long long y;

	if(i == j) {
		tree[node] = a[i];
		return a[i];
	}

	x = create_tree(i, (i+j)/2, node * 2);
	y = create_tree((i+j)/2 + 1, j, node * 2 + 1);

	tree[node] = x + y;

	return x + y;

}



int main()
{

	int n;
	int x;
	int y;
	int ch;
	int val;
	int t;
	int q;

	
	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &n);
		scanf("%d", &q);

		printf("Case %d:\n", cs);

			
		memset(a, 0, sizeof(a));
		memset(tree, 0, sizeof(tree));
		
		memset(lazy, 0, sizeof(lazy));

		for (int i = 0; i < q; i++) {
			scanf("%d", &ch);
			scanf("%d", &x);
			scanf("%d", &y);
			
			if(ch) {
				printf("%lld\n", query(0, n-1, x, y, 1));
			}

			else {
				scanf("%d", &val);
				update(0, n-1,x, y, 1, val);
			}

		}

	}
	
	
}
	
