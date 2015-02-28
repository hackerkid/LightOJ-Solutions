#include <iostream>
#include <math.h>
using namespace std;

int main()
{

	unsigned long long k;
	unsigned long long t;
	unsigned long long m;
	unsigned long long x;
	unsigned long long f;

	cin >> t;

	for (int i = 1; i <= t; i++) {
		cin >> k;
		x = ceil(sqrt(k));
		switch(k) {
			case 1:
				cout <<"Case "<<i<<": "<<1<<" "<<"1\n";
				continue;
				break;
			case 2:
				cout <<"Case "<<i<<": "<<1<<" "<<"2\n";
				continue;
				break;
			case 3:
				cout <<"Case "<<i<<": "<<2<<" "<<"2\n";
				continue;
				break;
			case 4:
				cout <<"Case "<<i<<": "<<2<<" "<<"1\n";
				continue;
				break;
		}


		if(x % 2 == 1) {
			m = (x - 1) * (x - 1);
			if(m + x >= k) {
				f = k - m;
				cout <<"Case "<<i<<": "<<x<<" "<<f<<"\n";
			}

			else {
				m = x * x;
				f = m - k;
				f++;
				cout <<"Case "<<i<<": "<<f<<" "<<x<<"\n";
			}

		}

		else {
			m = (x - 1) * (x - 1);
			if(m + x >= k) {
				f = k - m;
				cout <<"Case "<<i<<": "<<f<<" "<<x<<"\n";
			}

			else {
				m = x * x;
				f = m - k;
				f++;
				cout <<"Case "<<i<<": "<<x<<" "<<f<<"\n";
			}

		}

				
	}

}


