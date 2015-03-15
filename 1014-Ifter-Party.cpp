#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int main()
{
	int t;
	long long p;
	long long q;
	long long l;
	long long i;

	cin >> t;

	for (int j = 1; j <= t; j++) {
		scanf("%lld", &p); 
		scanf("%lld", &l); 
		p = p - l;
		vector <long long> a;
		vector <long long> b;


		for (i = 1; i * i < p; i++) {
			if(p % i == 0) {
				if(i > l) {
					a.push_back(i);
				}
				
				if((p / i) > l) {
					b.push_back(p / i);
				}
			}

		}

		if(i * i == p and i > l) {
			a.push_back(i);
		}

			


		printf("Case %d: ", j);

		for (int i = 0; i < a.size(); i++) {
			printf("%lld", a[i]);
			if(!(i == a.size() - 1 and b.size() == 0)) {
				printf(" ");
			}
		}

		for (int i = b.size() - 1; i >= 0; i--) {
			printf("%lld", b[i]);
			if(i != 0) {
				printf(" ");
			}
		}

		if(a.size() + b.size()) {
			printf("\n");
		}
		
		else {
			printf("impossible\n");
		}

	}


}

