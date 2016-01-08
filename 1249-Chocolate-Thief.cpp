#include <stdio.h>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int n;
	int t;
	int x;
	int y;
	int w;

	int sum;
	
	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		vector <int> arr;
		char names[200][1000];
		char temp[1000];

		scanf("%d", &n);
		
		sum = 0;

		for(int i = 0; i < n; i++) {
			scanf("%s", temp);
			
			strcpy(names[i], temp);

			scanf("%d", &x);
			scanf("%d", &y);
			scanf("%d", &w);

			sum += x * y * w;
			arr.push_back(x * y * w);

		}
		
		int ans = 0;
		int mini = arr[0];
		int pie;
		int ok = 0;
		char who[1000];
		char from[1000];
		pie = sum / n;

		for (int i = 0; i < n; i++) {
			if(arr[i] > pie) {
				strcpy(who, names[i]);
				ok = 1;
			}

			if(arr[i] < pie) {
				strcpy(from, names[i]);
				ok = 1;
			}
		}

		if(ok)
			printf("Case %d: %s took chocolate from %s\n", cs, who, from);
		else
			printf("Case %d: no thief\n", cs);
	}


}

