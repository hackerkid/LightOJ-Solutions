#include <queue>
#include <iostream>
#include <utility>
#include <limits.h>
#include <fstream>
#include <string.h>
#define ii pair <int, int>
#define pii pair <int, ii>
using namespace std;


int count = 0;
int check[100];
int a[100][100];
	
int test(int i, int n)
{
	for (int j = 0; j < n; j++) {
		if(i != j and (a[i][j] != INT_MAX or a[j][i] != INT_MAX) and check[j] == 0) {
			check[j] = 1;
			count++;
			test(j, n);
		}
	}

}


int prim()
{

	int ans[100][100];
	int already[100];
	long long total;
	total = 0;

	

	priority_queue  < pair<int, ii>,	vector <pair < int, ii> >, greater <pair < int, ii> > > q;

	int n;
	int m;

	int x;
	int y;
	int w;

	int n1;
	int n2;

	int dist = 0;
	
	pair <int, ii> temp;


	cin >> n;
	m = n * n;
	for (int i = 0; i < n; i++) {
		already[i] = -1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			total += a[i][j];
			ans[i][j] = INT_MAX;
			if(a[i][j] == 0) {
				a[i][j] = INT_MAX;
			}
		}

	}
+

	
	memset(check,  0, sizeof(check));
	count = 1;
	check[0] = 1;
	test(0, n);
	
	if(count != n) {
		
		return -1;
	}
		
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
				a[i][j] = min(a[i][j], a[j][i]);
		}
	}

	
	
	already[0] = 1;

	for (int i = 0; i < n; i++) {
		q.push(pii (a[0][i],(ii ( 0, i))));
	}

	for (int j = 1; j < n; j++) {

		do
		{
			temp = q.top();
			q.pop();
			w = temp.first;
			x = temp.second.first;
			y = temp.second.second;

		} while(already[x] != -1 and already[y] != -1 and !q.empty());
		ans[x][y] = w;
		dist += w;

		if(already[x] == -1) {
			for (int i = 0; i < n; i++) {
				q.push(pii(a[x][i], ii(x, i)));
				already[x] = 1;
			}

		}

		else {
			for (int i = 0; i < n; i++) {
				q.push(pii(a[y][i], ii(y, i)));
				already[y] = 1;
			}

		}


	}

	return (total - dist);

	


}



int main()
{
	int t;
	scanf("%d", &t);
	for (int cases = 1; cases <= t; cases++) {
		printf("Case %d: %d\n", cases, prim());
	}
}



		

	
