#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int palin[1005][1005];


int generate(string x)
{	
	int n;
	int e;
	n = x.length();

	for (int i = 0; i < n; i++) {
		palin[i][i] = 1;
	}

	for (int length = 2; length <= n; length++) {
		for (int s = 0; s <= n - length; s++) {
			e = s + length - 1;


			if(length == 2) {
				palin[s][e] = (x[s] == x[e]);

			}

			else {
				palin[s][e] = ((x[s] == x[e]) and palin[s+1][e-1]);
			}
		}
	}
}





int main()
{

	int t;
	int explore[1001][1001];
	int n;

	scanf("%d", &t);
	for (int cases = 1; cases <= t; cases++) {
		
		int l;
		char inp[1005];
		string x;
		
		scanf("%s", inp);
		
		memset(explore, 0, sizeof(explore));
		memset(palin, 0, sizeof(palin));

		x = inp;
		n = x.length();


		generate(x);

		for (int i = n; i >= 0; i--) {
			for (int j = n; j >= i; j--) {
	
				if(j == n) {
					explore[i][j] = j - i;
					continue;
				}
	


				if(palin[i][j]) {
					explore[i][j] = min( 1 +  explore[j+1] [j+1], explore[i][ j+1]);
					continue;
				}

				else {
					explore[i][j] = explore[i][j+1];
					continue;
				}

			}

		}

		
		printf("Case %d: %d\n", cases, explore[0][0]);
	}

}

	
