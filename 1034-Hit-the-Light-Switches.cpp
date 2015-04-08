#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <stack>
using namespace std;

bool visited[10004];
int n;

vector < vector <int > > graph;
vector < vector <int > > transpose;
stack <int> track;

int dfs(int j)
{
	visited[j] = true;
	int t;

	for (int i = 0; i < graph[j].size(); i++) {
		t = graph[j][i];
		
		if(visited[t] == false) {
			dfs(t);
		}

	}

	track.push(j);

}

int dfsbro(int j)
{
	visited[j] = true;
	int t;
	for (int i = 0; i < transpose[j].size(); i++) {
		t = transpose[j][i];
		if(visited[t] == false) {
			dfsbro(t);
		}

	}


}

int dfsbro2(int j)
{
	visited[j] = true;
	int t;
	for (int i = 0; i < graph[j].size(); i++) {
		t = graph[j][i];
		if(visited[t] == false) {
			dfsbro2(t);
		}

	}


}


int trans()
{
	vector < vector <int > > temp(n+5);
	swap(temp, transpose);
	int t;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			t = graph[i][j];
			transpose[t].push_back(i);
		}

	}

}

int main()
{

	int x;
	int y;
	int m;
	int count;
	int tt;
	int t;
	scanf("%d", &t);

	for (int cases = 1; cases <= t; cases++) {
		scanf("%d", &n);
		scanf("%d", &m);
		vector < vector <int > > temp(n+5);
		memset(visited, 0, sizeof(visited));
		stack <int> track2;
		swap(track, track2);
		swap(temp, graph);

		for (int i = 0; i < m; i++) {
			scanf("%d", &x);
			scanf("%d", &y);
			graph[x].push_back(y);
		}

		for (int i = 1; i <= n; i++) {
			if(visited[i] == false) {
				dfs(i);
			}

		}


	//	trans();

		memset(visited, 0, sizeof(visited));
		count = 0;
		
		while(!track.empty()) {
			tt = track.top();
			track.pop();
			if(visited[tt] == false) {
				dfsbro2(tt);
				count++;
			}

		}

		printf("Case %d: %d\n", cases, count);

	}


}


