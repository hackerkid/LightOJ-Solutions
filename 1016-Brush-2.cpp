#include <vector>
#include <set>
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{

	int t;
	int n;
	int x;
	int y;
	int w;
	int temp;
	int count;

	scanf("%d", &t);

	for (int j = 1; j <= t; j++) {
		scanf("%d", &n);
		scanf("%d", &w);
		vector <int> a;


		for (int i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			a.push_back(y);
		}

		set <int> s(a.begin(), a.end());
		a.assign(s.begin(), s.end());

		temp = a[0];
		count = 1;

		for (int i = 0; i < a.size(); i++) {
			if(temp + w < a[i]) {

				temp = a[i];
				
				count++;
			}

		}

		printf("Case %d: %d\n", j, count);


	}


}
			
