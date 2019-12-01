#include<bits/stdc++.h>
#define ii pair<int, int>
using namespace std;


int dijkstra(vector < vector <pair <int, int > > > x, int n, int my){
	
	pair <int, int> temp;
	vector <int> dis(n, INT_MAX);
	priority_queue < ii, vector <ii>, greater <ii> > q;
	int bro;
	temp.first = 0;
	temp.second = my;
	ii top;
	q.push(temp);
	int distance;
	int index;
	int d;
	int j;
	while (!q.empty()) {
		top = q.top();
		q.pop();

		index = top.second;
		distance = top.first;

		if(distance <= dis[index]) {
			dis[index] = distance;
			for (int i = 0; i < x[index].size(); i++) {
				temp = x[index][i];
				d = temp.first;
				j = temp.second;
				
				bro = max(d,distance);
				if(bro < dis[j]) {
					dis[j] = bro;
					q.push(ii(dis[j], j));
				}


			}


		}


	}

	for (int i = 0; i < n; i++) {
		if(dis[i] == INT_MAX) {
			cout << "Impossible\n";
		}
		else {
			cout << dis[i] << endl;
		}
	}



}


int main()
{

	int a;
	int b;
	int w;

	int m;
	int n;
	int t;
	int k;
	int my;
	pair <int, int> temp;
	//fstream cin;
	//cin.open("1002.in", ios::in);

	cin >> t;

	for (int j = 1; j <= t; j++) {
		cin >> n;
		vector < vector <pair <int, int> > > x(n);
		cin >> m;

		for (int i = 1; i <= m; i++) {
			cin >> a;
			cin >> b;
			cin >> w;

			temp.first = w;
			temp.second = b;
			int k;
			int kk;

			for(k = 0; k < x[a].size(); k++) {
				if(x[a][k].second == b)
					break;
			}
			
			for(kk = 0; kk < x[b].size(); kk++) {
				if(x[b][kk].second == a)
					break;
			}

			if(k == x[a].size()) {
				x[a].push_back(temp);
				x[b].push_back(ii(w, a));
			}

			else {
				if(temp.first < x[a][k].first ) {
					x[a][k] = temp;
					x[b][kk] = ii(w, a);
				}

			}

		}

		cin >> my;
		cout << "Case "<<j<<":"<<endl;
		dijkstra(x, n, my);


	}


}


