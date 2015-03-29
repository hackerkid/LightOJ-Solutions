#include <iostream>
#include <algorithm>
#include <stdio.h>
#define rint(x) scanf("%d", &x)
using namespace std;

int fact(int x)
{
	int ans = 1;
	
	while(x) {
		ans = ans * x;
		x--;
	}

	return ans;

}

int main()
{
	char c;
	int t;
	int k;
	int n;
	int tot;


	rint(t);

	for (int p = 1; p <= t; p++) {
		c = 'A';
		string a;
		rint(n);
		rint(k);
		
		for (int i = 0; i < n; i++) {
			a = a + c;
			c = c + 1;
		}

		printf("Case %d:\n", p);
		
		
		if(n < 5) {
			
			tot = fact(n);
			
			if(k < tot) {
			
				for (int i = 0; i < k; i++) {
					cout << a << endl;
					next_permutation(a.begin(), a.end());

				}

			}

			else {
			
				if(k >= tot) {
			
					for (int i = 0; i < tot; i++) {
						cout << a << endl;
						next_permutation(a.begin(), a.end());

					}
				}
			}

		}

		else {
			
			for (int i = 0; i < k; i++) {
				cout << a << endl;
				next_permutation(a.begin(), a.end());
			}

		}

	}

}

