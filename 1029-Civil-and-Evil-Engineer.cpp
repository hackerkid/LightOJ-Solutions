#include <queue>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <string.h>
using namespace std;

vector < vector < pair <int, int> > > graph;
int n;

int prim()
{

	priority_queue  < pair < int, pair < int, int> >, vector < pair <int, pair <int, int> > > , greater < pair <int, pair <int, int > > > > q;
	bool a[10004];
	memset(a, 0, sizeof(a));

	pair <int, pair <int, int> > temp;
	pair <int, int> node;
	int count = 0;
	int x;
	int y;
	int w;
	int ans;

	ans = 0;

	for (int i = 0; i < graph[0].size(); i++) {
		node = graph[0][i];
		temp.first = node.second;
		temp.second.first = 0;
		temp.second.second = node.first;
		q.push(temp);
		temp.second.second = 0;
		temp.second.first = node.first;
		q.push(temp);
		count = 1;
		a[0] = 1;
	}


	while (count <= n and !q.empty()) {
		temp = q.top();
		q.pop();
		x = temp.second.first;
		y = temp.second.second;
		w = temp.first;	
		if(a[x] and a[y]) 
			continue;

		if(!a[x]) {
			ans += w;
			a[x] = 1;
			
			for (int i = 0; i < graph[x].size(); i++) {
				temp.first = graph[x][i].second;
				temp.second.first = x;
				temp.second.second = graph[x][i].first;
				q.push(temp);
				temp.second.second = x;
				temp.second.first = graph[x][i].first;
				q.push(temp);
			}

			count++;

		}

		else {
			ans += w;
			a[y] = 1;
			
			for (int i = 0; i < graph[y].size(); i++) {
				temp.first = graph[y][i].second;
				temp.second.first = y;
				temp.second.second = graph[y][i].first;
				q.push(temp);
				temp.second.second = y;
				temp.second.first = graph[y][i].first;
				q.push(temp);
			}
			count++;

		}



	}

	return ans;


}

int prim2()
{

	priority_queue  < pair < int, pair < int, int> > > q;
	bool a[10004];
	memset(a, 0, sizeof(a));

	pair <int, pair <int, int> > temp;
	pair <int, int> node;
	int count = 0;
	int x;
	int y;
	int w;
	int ans;

	ans = 0;

	for (int i = 0; i < graph[0].size(); i++) {
		node = graph[0][i];
		temp.first = node.second;
		temp.second.first = 0;
		temp.second.second = node.first;
		q.push(temp);
		temp.second.second = 0;
		temp.second.first = node.first;
		q.push(temp);
		count = 1;
		a[0] = 1;
	}


	while (count <= n and !q.empty()) {
		temp = q.top();
		q.pop();
		x = temp.second.first;
		y = temp.second.second;
		w = temp.first;
		if(a[x] and a[y]) 
			continue;

		if(!a[x]) {
			ans += w;
			a[x] = 1;
			
			for (int i = 0; i < graph[x].size(); i++) {
				temp.first = graph[x][i].second;
				temp.second.first = x;
				temp.second.second = graph[x][i].first;
				q.push(temp);
				temp.second.second = x;
				temp.second.first = graph[x][i].first;
				q.push(temp);
			}

			count++;

		}

		else {
			ans += w;
			a[y] = 1;
			
			for (int i = 0; i < graph[y].size(); i++) {
				temp.first = graph[y][i].second;
				temp.second.first = y;
				temp.second.second = graph[y][i].first;
				q.push(temp);
				temp.second.second = y;
				temp.second.first = graph[y][i].first;
				q.push(temp);
			}
			count++;

		}



	}

	return ans;

}



int main()
{

	int t;
	int x;
	int y;
	int w;
	int ok;

	pair <int, int> to;
	scanf("%d", &t);

	for(int cases = 1; cases <= t; cases++) {
		scanf("%d", &n);
		vector < vector <pair <int, int> > > temp(n+1);
		swap(temp, graph);
		while (scanf("%d %d %d", &x, &y, &w)==3 && w) {

				
			to.first = y;
			to.second = w;

			graph[x].push_back(to);
			to.first = x;
			to.second = w;
			graph[y].push_back(to);
		}
		x = prim();
		y = prim2();
		
		y = y + x;
		if(y % 2 == 0) {
			y = y / 2;
			printf("Case %d: %d\n", cases, y);
		}

		else {
			printf("Case %d: %d/2\n", cases, y);
		}

	}


}



