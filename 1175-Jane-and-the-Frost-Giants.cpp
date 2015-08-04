#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

queue < pair <int, int> > q;
queue < pair <int, int> > fire;
char a[210][210];
int vis[210][210];
int ii;
int jj;
int r;
int c;
int suc;
int count;

int fireUp()
{
		int l;
		pair <int, int> temp;
		l = fire.size();

		for (int i = 0; i < l; i++) {
			temp = fire.front();
			fire.pop();

			ii = temp.first;
			jj = temp.second;
			
			if(ii + 1 < r and a[ii+1][jj] == '.') {
				fire.push(make_pair(ii+1, jj));
				a[ii+1][jj] = 'F';

			}
			
			if(jj + 1 < c and a[ii][jj + 1] == '.') {
				fire.push(make_pair(ii, jj+1));
				a[ii][jj + 1] = 'F';
			}

			if(ii - 1 >= 0 and a[ii - 1][jj] == '.') { 
				fire.push(make_pair(ii-1, jj));
				a[ii - 1][jj] = 'F';
			}

			if(jj - 1 >= 0 and a[ii][jj-1] == '.') { 
				fire.push(make_pair(ii, jj - 1));
				a[ii][jj - 1] = 'F';
			}

			
			
			

		}
}

int nextState()
{
	int l;
	pair <int, int> temp;

	while(!q.empty()) {
		count++;
		
		l = q.size();
		for (int i = 0; i < l; i++) {


			temp = q.front();
			q.pop();

			ii = temp.first;
			jj = temp.second;
			
			if(a[ii][jj] == 'F') {
				continue;
			}

			if(ii + 1 >= r) {
				suc = 1;
				break;
			}

			else {
				if(a[ii+1][jj] == '.' and !vis[ii+1][jj]) {
					q.push(make_pair(ii+1, jj));
					vis[ii+1][jj] = 1;
				}

			}
				
			if(jj + 1 >= c) {
				suc = 1;
				break;
			}

			else {
				if(a[ii][jj + 1] == '.' and !vis[ii][jj+1]) {
					q.push(make_pair(ii, jj + 1));
					vis[ii][jj+1] = 1;
				}

			}
				
			if(ii - 1 < 0) {
				suc = 1;
				break;
			}

			else {
				if(a[ii - 1][jj] == '.' and !vis[ii-1][jj]) {
					q.push(make_pair(ii -1, jj));
					vis[ii-1][jj] = 1;
				}

			}
				
			if(jj - 1 < 0) {
				suc = 1;
				break;
			}

			else {
				if(a[ii][jj - 1] == '.' and !vis[ii][jj-1]) {
					q.push(make_pair(ii, jj - 1));
					vis[ii][jj-1] = 1;
				}

			}
				
		}


		if(suc == 1 or suc == 2) {
			break;
		}
		fireUp();

	}
	
	if(suc == 1) {
		return count;
	}

	else {
		return -1;
	}


}


int readinput()
{
	cin >> r;
	cin >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
			
			if(a[i][j] == 'F') {
				fire.push(make_pair(i, j));

			}
				
			if(a[i][j] == 'J') {
				ii = i;
				jj = j;
				a[i][j] = '.';
			}
		}
	}
	
	q.push(make_pair(ii, jj));
}

int main()
{

	int t;

	cin >> t;

	for (int cs = 1; cs <= t; cs++) {

		queue < pair <int, int> > tq;
		queue < pair <int, int> > tfire;
		int x;

		swap(q, tq);
		swap(fire, tfire);
		memset(vis,0,  sizeof(vis));

		readinput();

		pair <int, int> temp;

		temp = fire.front();


		
		suc = 0;
		count = 0;
		x = nextState();

		if(x != -1) {
			printf("Case %d: %d\n", cs, x);
		}

		else {
			printf("Case %d: IMPOSSIBLE\n", cs);
		}

	}


}

