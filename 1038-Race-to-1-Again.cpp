#include <iostream>
#include <stdio.h>
#define N 100000

using namespace std;

double pro[N + 4];
int count[N+ 4];
int main()
{
	double sum;
	double temp;
	int x;
	int n;


	for (int i = 2; i <= N; i++) {
		sum = pro[i];
		n = count[i];
		n += 2;
		sum += n;


		sum = sum / (double) (n -1);
		pro[i] = sum;

		for (int j =  2 * i; j <= N; j = j + i) {
			count[j]++;
			pro[j] += sum;
		}

	}

	int t;
	scanf("%d", &t);

	for (int cs = 1; cs<= t; cs++) {
		scanf("%d", &x);

		printf("Case %d: %lf\n", cs, pro[x]);
	}

}






