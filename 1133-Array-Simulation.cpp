#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	long long a[1000];
	int t;
	int n;
	char choice;
	long long x;
	long long y;
	int count;
	int q;

	cin >> t;

	for (int cs = 1; cs <= t; cs++) {
		cin >> n;
		cin >> q;
		count = 0;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		for (int k = 0; k < q; k++) {
//			scanf("%c", &choice);
			cin >> choice;
			switch(choice) {
				case 'S': 
					cin >> x;
					for (int i = 0; i < n; i++) {
						a[i] += x;
					}

					break;
				
				case 'M': 
					cin >> x;
					for (int i = 0; i < n; i++) {
						a[i] *= x;
					}

					break;
				
				case 'D': 
					cin >> x;
					for (int i = 0; i < n; i++) {
						a[i] /= x;
					}

					break;
				
				case 'R': 
					for (int i = 0, j = n-1; i < j; i++, j--) {
						swap(a[i], a[j]);
					}
					break;
				
				case 'P': 
					cin >> x;
					cin >> y;
					swap(a[x], a[y]);
					break;

			}



		}	

		printf("Case %d:\n", cs);
		
		for (int i = 0; i < n; i++) {
			printf("%lld", a[i]);
			if(i != n-1) {
				printf(" ");
			}

			else {
				printf("\n");
			}

		}





	}


}
				




