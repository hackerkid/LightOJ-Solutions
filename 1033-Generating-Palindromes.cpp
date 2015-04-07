#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int pali(string x, string y)
{
	int a[110][110];
	memset(a, 0, sizeof(a));
	
	for (int i = x.length(); i >= 0; i--) {
		for (int j = y.length(); j >= 0; j--) {
			if(i == x.length() or j == y.length()) {
				a[i][j] = 0;
				continue;
			}

			if(x[i] == y[j]) {
				a[i][j] = 1 + a[i+1][j+1];
				continue;
			}

			a[i][j] = max(a[i+1][j], a[i][j+1]);

		}

	}


	return x.length() - a[0][0];


}




int main()
{

	string x;
	string y;
	char temp[110];
	int t;
	scanf("%d", &t);
	
	for (int cases = 1; cases <= t; cases++) {
		scanf("%s", temp);
		x = temp;
		for (int i = 0, j = x.length() - 1; i < j; i++, j--) {
			swap(temp[i], temp[j]);
		}
		y = temp;
		printf("Case %d: %d\n",cases, pali(x, y));
	}

}

