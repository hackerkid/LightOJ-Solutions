#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

int main()
{
	int t;
	int jmax;
	int n;
//fstream cin;
//cin.open("1004.in", ios::in);
	unsigned long long a[300][300];
	unsigned long long inp[300][300];
	n = 4;
	cin >> t;
	for (int k = 1; k <= t; k++) {
		
		cin >> n;
		memset(a, 0, sizeof(a));
		memset(inp, 0, sizeof(inp));
		
		for (int i = 0; i <= ((2 * n) - 1); i++) {
			if(i < n) 
				jmax = i;
			else 
				jmax = 2 * n - i;
		
			for(int j = 0; j < jmax; j++) {
				cin >> inp[i][j];
			}

		}
		
		for (int i =  ((2 * n) - 1); i >= 0; i--) {
			
			if(i < n) {
				jmax = i+1;
			}
			
			else { 
				jmax = 2 * n - i;
			}
			
			if(i < n) {
			
				for(int j = 0; j < jmax; j++) {

					if(i == ((2 * n) - 1)) {
						a[i][j] = inp[i][j];
						continue;
					}
					
					a[i][j] = max((inp[i][j] + a[i+1][j]), (inp[i][j] + a[i+1][j+1]));
				}
			}

			else {
				
				for (int j = jmax - 1; j >= 0; j--) {
					if(i == ((2 * n) - 1)) {
						a[i][j] = inp[i][j];
						continue;
					}
				
					if(j -1 >= 0) {
						a[i][j] = max((inp[i][j]+a[i+1][j]), (inp[i][j]+ a[i+1][j-1]));
					}

					else {
						a[i][j] = a[i+1][j] + inp[i][j];
					}

				}

			}

		}

		cout <<"Case "<<k<<": "<< a[0][0]<<endl;

	}
}

