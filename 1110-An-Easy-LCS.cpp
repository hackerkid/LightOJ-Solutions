#include <iostream>
#include <stdio.h>
using namespace std;

string minim(string x, string y)
{
	if(x.length() < y.length()) {
		return y;
	}
	
	if(x.length() > y.length()) {
		return x;
	}

	for (int i = 0; i < x.length(); i++) {
		if(x[i] < y[i]) {
			return x;
		}

		if(x[i] > y[i]) {
			return y;
		}

	}

	return x;

}

	

int main()
{

	int t;
	string x;
	string y;
	string temp;
	char xx[110];
	char yy[110];
	char ans[110];
	int n;
	int m;
	scanf("%d", &t);
	for (int cs = 1; cs <= t; cs++) {
		
		string a[110][110];

		scanf("%s", xx);
		scanf("%s", yy);
	
		x = xx;
		y = yy;

		n = x.length();
		m = y.length();

		for (int i = n; i >= 0; i--) {
			for (int j = m; j >= 0; j--) {
				if(i == n or j == m) {
					a[i][j] = "";
					continue;
				}

				if(x[i] == y[j]) {
					a[i][j] = x[i] + a[i+1][j+1];
					continue;
				}

				a[i][j] = minim(a[i+1][j],a[i][j+1]);
			}


		}

		for (int i = 0; i < a[0][0].length(); i++) {
			ans[i] = a[0][0][i];
		}

		ans[a[0][0].length()] = '\0';

		if(a[0][0].length() != 0) {
			printf("Case %d: %s\n", cs, ans);

		}

		else {
			printf("Case %d: :(\n", cs);
		}
		
	}

}








