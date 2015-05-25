#include <iostream>
#include <stdio.h>
#include <utility>
#include <vector>
#include <string.h>
using namespace std;

int main()
{

	int t;
	int x;
	int w;
	int y;
	int total;
	int sofar;
	bool visited[110];
	int count;
	int n;


	scanf("%d", &t);
	for(int cs = 1; cs <= t; cs++) {
		cin >> n;

		vector < vector < pair <int, int > > > a(n+3);
		memset(visited, 0, sizeof(visited));
		total = 0;
		sofar = 0;

		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			scanf("%d", &y);
			scanf("%d", &w);

			a[x].push_back(make_pair(y, w));
			a[y].push_back(make_pair(x, -w));
			total += w;
		}
		
		int i;

		i = 1;
		count = 0;
		visited[1] = 1;
		while (count < n -1) {
			
			x = a[i][0].first;
			
			if(visited[x] == 0) {
				w = a[i][0].second;
				visited[x] = 1;
				
				if(w < 0) {
					w = w * -1;
					sofar += w;
				}

				i = x;

			}

			else {
				x = a[i][1].first;
				visited[x] = 1;
				w = a[i][1].second;
				
				if(w < 0) {
					w = w * -1;
					sofar += w;
				}

				i = x;
			}


			count++;

		}

		if(x = a[i][0].first == 1) {
			w = a[i][0].second;
			if(w < 0) {
				w = w * -1;
				sofar += w;
			}

		}

		else {
			w = a[i][1].second;
			if(w < 0) {
					w = w * -1;
					sofar += w;
			}

		}

		printf("Case %d: %d\n", cs, min(sofar, total - sofar));

	}


}






