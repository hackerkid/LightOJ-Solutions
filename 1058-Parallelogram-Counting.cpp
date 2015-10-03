#include <iostream>
#include <stdio.h>
#include <map>
#include <utility>
#include <vector>
#include <algorithm>
#define pii pair <int, int> 
using namespace std;

vector < pii > v;
vector < pii > m;

int main()
{

	int t;
	int x;
	int y;
	int n;

	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		
		scanf("%d", &n);

		m.clear();
		v.clear();

		
		pii temp;
		pii p1;
		pii p2;
		int ans;
		int top;
		
		ans = 0;


		for (int i = 0; i < n; i++) {
			scanf("%d", &temp.first);
			scanf("%d", &temp.second);
			v.push_back(temp);
		}

		for (int i = 0; i < v.size(); i++) {
			for (int j = i + 1; j < v.size(); j++) {
				p1 = v[i];
				p2 = v[j];

				x = v[i].first + v[j].first;
				y = v[i].second + v[j].second;

				temp.first = x;
				temp.second = y;

				m.push_back(temp);


			}

		}

		sort(m.begin(), m.end());
		top = 0;
		

		for (int i = 1; i < m.size(); i++) {
			if((m[i].first == m[i-1].first) and (m[i].second == m[i-1].second)) {
				top++;
			}

			else {
				ans = ans + (top * (top + 1)) / 2;
				top = 0;
			}
		}


		printf("Case %d: %d\n",cs, ans);
	}

}



			

