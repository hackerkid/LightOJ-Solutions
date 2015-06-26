#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;


bool cmp(pair <int, int> a, pair<int,int> b)
{

	if(a.first < b.first) {
		return 1;
	}

	if(a.first > b.first) {
		return 0;
	}

	if(a.second > b.second) {
		return 1;
	}

	return 0;

}




int main()
{
	

	int x;
	int t;

	vector < pair <int, int> > a(1001);

	for (int i = 1; i <= 1000; i++) {
		a[i].second = i;
		a[i].first = 0;
	}

	for (int i = 1; i <= 1000; i++) {
			for (int j = i; j <= 1000; j = j + i) {
				a[j].first++;
			}


	}

	sort(a.begin(), a.end(), cmp);

	scanf("%d", &t);


	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &x);
		printf("Case %d: %d\n", cs, a[x].second);

	}


}

