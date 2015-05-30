#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{

	int t;


	cin >> t;

	for (int cs = 1; cs <= t; cs++) {
		vector <long long int> a(4);
		cin >> a[0];
		cin >> a[1];
		cin >> a[2];

		sort(a.begin(), a.begin() + 3);

		if((a[0] * a[0] + a[1] * a[1]) == (a[2] * a[2])) {
			printf("Case %d: yes\n", cs);
		}

		else {
			printf("Case %d: no\n", cs);
		}

	}


}

