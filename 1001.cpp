#include <iostream>

using namespace std;

int main()
{

	int t;
	int a;
	int b;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> a;
		
		b = a / 2;
		a = a % 2 + a / 2;
		cout << a << " "<<b << endl;

	}		

}
