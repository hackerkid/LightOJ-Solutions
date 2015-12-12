#include <iostream>
using namespace std;

int main()
{
	
	int x;
	string inp;
	int t;
	int sum;
	int n;

	sum = 0;
	cin >> t;

	for (int cs = 1; cs <= t; cs++) {
		cin >> n;
		sum = 0;
		cout << "Case " << cs <<":"<< endl;
		for (int i = 0; i < n; i++) {
			cin >> inp;
			if(inp == "donate") {
				cin >> x;
				sum += x;
			}
			else {
				cout << sum << endl;;
			}

		}
	}

}
	
