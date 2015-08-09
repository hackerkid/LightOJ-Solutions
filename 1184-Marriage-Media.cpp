#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

int n;
int m;



struct node
{
	int age;
	int height;
	int divorce;

};

node men[60];
node women[60];
int seen[60];
int husband[60];

int ok(int i, int j)
{

	if((men[i].divorce == women[j].divorce) and (abs(men[i].height - women[j].height) <= 12) and (abs(men[i].age - women[j].age) <= 5)) {
		return true;
	}

	return false;

}

int bpm(int manId)
{

	for (int i = 0; i < m; i++) {
		if(ok(manId, i)) {
			if(seen[i])
				continue;

			seen[i] = 1;

			if(husband[i] < 0 or bpm(husband[i])) {
				husband[i] = manId;
				return true;
			}

		}

	}

	return false;

}



int main()
{

	int t;
	int count;
	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &n);
		scanf("%d", &m);

		for (int i = 0; i < n; i++) {
			scanf("%d", &men[i].height);
			scanf("%d", &men[i].age);
			scanf("%d", &men[i].divorce);
		}

		for (int i = 0; i < m; i++) {
			scanf("%d", &women[i].height);
			scanf("%d", &women[i].age);
			scanf("%d", &women[i].divorce);
		}

		memset(husband, -1, sizeof husband);
		count = 0;

		for (int i = 0; i < n; i++) {
			memset(seen, 0, sizeof seen);
			if(bpm(i)) {
				count++;
			}

		}

		printf("Case %d: %d\n", cs, count);
	
	}

}

