#include <map>
#include <string.h>
#include <queue>
#include <iostream>
#include <utility>
#include <limits.h>
#include <stdio.h>
#define ii pair <int, int>
#define pii pair <int, ii>
using namespace std;


int n;
int a[100][100];
int count;
int compo[100];
int marked[100];
int tested;

int prims()
{

	int distance_matrix[100][100];
	int ans[100][100];
	int already_visited[100];

	

	priority_queue  < pair<int, ii>,	vector <pair < int, ii> >, greater <pair < int, ii> > > prims_prio_q;

	int number_nodes;
	int number_edges;

	int node_1;
	int node_2;
	int p;
	int r;
	int temp_weight;

	int final_distance = 0;
	
	pair <int, ii> pair_temp;

	number_nodes = count;


	for (int i = 0; i < number_nodes; i++) {
		already_visited[i] = -1;
	}

	for (int i = 0; i < number_nodes; i++) {
		for (int j = 0; j < number_nodes; j++) {
			distance_matrix[i][j] = INT_MAX;
			ans[i][j] = INT_MAX;
		}

	}


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			p = compo[i];
			r = compo[j];
			
			if(a[i][j] != -1 and a[j][i] != -1 and a[i][j] != 0) {
				distance_matrix[p][r] = min(a[i][j], distance_matrix[p][r]);
				distance_matrix[r][p] = min(a[j][i], distance_matrix[r][p]);
			}
			
		}
	}
	
	
	already_visited[0] = 1;

	for (int i = 0; i < number_nodes; i++) {
		prims_prio_q.push(pii (distance_matrix[0][i],(ii ( 0, i))));
	}

	for (int j = 1; j < number_nodes; j++) {

		do
		{
			pair_temp = prims_prio_q.top();
			prims_prio_q.pop();
			temp_weight = pair_temp.first;
			node_1 = pair_temp.second.first;
			node_2 = pair_temp.second.second;

		} while(already_visited[node_1] != -1 and already_visited[node_2] != -1 and !prims_prio_q.empty());
		ans[node_1][node_2] = temp_weight;
		final_distance += temp_weight;

		if(already_visited[node_1] == -1) {
			for (int i = 0; i < number_nodes; i++) {
				prims_prio_q.push(pii(distance_matrix[node_1][i], ii(node_1, i)));
				already_visited[node_1] = 1;
			}

		}

		else {
			for (int i = 0; i < number_nodes; i++) {
				prims_prio_q.push(pii(distance_matrix[node_2][i], ii(node_2, i)));
				already_visited[node_2] = 1;
			}

		}


	}

	return  final_distance;

	



}




int explore(int i)
{	
	for (int j = 0; j < n; j++) {
		if(a[i][j] == 0 and compo[j] == -1) {
			compo[j] = count;
			explore(j);
		}

	}

}

int goCheck(int i)
{

	for (int j = 0; j < n; j++) {
		if(a[i][j] != -1 and marked[j] == 0) {
			marked[j] = 1;
			tested++;
			goCheck(j);
		}
	}

}


int main()
{
	int t;
	int m;
	string x;
	string y;
	
	int xx;
	int yy;
	int w;

	cin >> t;

	for (int cases = 1; cases <=t; cases++) {
		n = 0;
		count = 0;
		map <string, int> mapping;
		memset(a, -1, sizeof(a));
		memset(compo, -1, sizeof(compo));
		cin >> m;

		for (int i = 0; i < m; i++) {
			cin >> x;
			cin >> y;
			cin >> w;
			
			if(mapping.count(x) == 0) {
				mapping[x] = n;
				xx = n;
				n++;
			}

			else {
				xx = mapping[x];
			}

			if(mapping.count(y)==0) {
				mapping[y] = n;
				yy = n;
				n++;
			}

			else {
			 	yy = mapping[y];
			}
			
			if(a[xx][yy] == -1) {
				a[xx][yy] = w;
				a[yy][xx] = w;
			}

			else {
				a[xx][yy] = min(w, a[xx][yy]);
				a[yy][xx] = min(w, a[yy][xx]);
			}
		}


		for (int i = 0; i < n; i++) {
			if(compo[i] == -1) {
				compo[i] = count;
				explore(i);
				count++;

			}

		}

		tested = 1;
		memset(marked, 0, sizeof(marked));
		marked[0] = 1;
		goCheck(0);

		
		if(tested != n) {
			printf("Case %d: Impossible\n", cases);
			
		}

		else {

			printf("Case %d: %d\n", cases, prims());
		}



	}


}




