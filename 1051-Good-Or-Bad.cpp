#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;

int ab;
int ok;
bool ans[55][1000];
vector <int> x;
string a;

int check(int n)
{
	
	int acount = 0;
	int bcount = 0;
	int qcount = 0;
	int i;

	for ( i = 0; i < a.length(); i++) {
			

		if(a[i] == 'A' or a[i] == 'E' or a[i] == 'I' or a[i] == 'O' or a[i] == 'U') {
			acount++;
			bcount = 0;
			a[i] = 'A';
		}
		else {
			acount = 0;
			if(a[i] != '?') {
				bcount++;
				a[i] = 'B';
			}

			else {
				bcount = 0;
				qcount++;
			}
		}

		if(acount == 3 or bcount == 5) {
			
			break;
		}
	}

		if(acount == 3 or bcount == 5) {
			return 0;
		}

		else {
			return 1;
		}

}

int explore(int i)
{
	
	int t;
	int temp;
	int mul = 1;


	temp = 0;

	if(i >= x.size()) {
		ok++;
		return 0;
	}

	t = x[i];

	a[t] = 'A';
	
	for (int j = 0; (t - j) >= 0 and j <= 5; j++) {
		temp = temp + ((a[t-j] - 'A') * mul);
		mul *= 2;
	}
	if(check(t)) {

		if(ans[i][temp] == 0) {
			explore(i+1);
			ans[i][temp] = 1;
		}

	}

	else {
		ab++;
	}
	
	mul = 1;

	a[t] = 'B';
	
	temp = 0;

	for (int j = 0; (t - j) >= 0 and j <= 5; j++) {
		temp += (a[t-j] - 'A') * mul;
		mul *= 2;
	}
	
	if(check(t)) {

		if(ans[i][temp] == 0) {
			explore(i+1);
			ans[i][temp] = 1;
		}

	}

	else {
		ab++;
	}

	a[t] = '?';

}
		
			




int main()
{

	int t;
	int acount;
	int bcount;
	int qcount;
	int i;

	cin >> t;

	for (int cs = 1; cs <= t; cs++) {
		cin >> a;

		vector <int> temp;
		swap(x, temp);
		acount = 0;
		bcount = 0;
		qcount = 0;

		for ( i = 0; i < a.length(); i++) {
			

			if(a[i] == 'A' or a[i] == 'E' or a[i] == 'I' or a[i] == 'O' or a[i] == 'U') {
				acount++;
				bcount = 0;
				a[i] = 'A';
			}

			else {
				acount = 0;
				if(a[i] != '?') {
					bcount++;
					a[i] = 'B';
				}

				else {
					bcount = 0;
					qcount++;
				}
			}

			if(acount == 3 or bcount == 5) {
				break;
			}

		}

		if(qcount == 0) {
			if(acount == 3 or bcount == 5) {
				printf("Case %d: BAD\n", cs); 
			}

			else {
				printf("Case %d: GOOD\n", cs); 
			}

		}

		else {
			for (int i = 0; i < a.length(); i++) {
				if(a[i] == '?') {
					x.push_back(i);
				}

			}

			ab = 0;
			ok = 0;
			memset(ans, 0, sizeof(ans));
			explore(0);
			
			if(ab and ok) {
				printf("Case %d: MIXED\n", cs); 
			}

			if(ab and ok == 0) {
				printf("Case %d: BAD\n", cs); 
			}

			if(ab == 0 and ok) {
				printf("Case %d: GOOD\n", cs); 
			}




		}

	}


}
