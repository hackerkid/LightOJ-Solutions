#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#define white 0
#define gray 1
#define black 2
using namespace std;

vector < vector <string> > a;
map <string, int> hash;
vector <int> visi;
int ok;

int count;
int wow(string x)
{
	int t;
	int k;
	string temp;
	t = hash[x];
	visi[t] = gray;
	for (unsigned int i = 0; i < a[t].size(); i++) {
		temp = a[t][i];
		if(visi[hash[temp]] == gray) {
			ok = 0;
			return 0;
		} else {
			wow(temp);
		}
	}
	visi[t] = black;
}
int main()
{

	int t;
	int m;
	int yes;
	int tot;
	int c;
	c = 1;
	tot = 0;
	string x;
	string y;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> m;
		vector <string> backup;
		vector < vector <string> > aa(10005);
		map <string, int> has;

		swap(aa, a);
		swap(has, hash);
		count = -1;
		ok = 1;
		
		for (int j = 0; j < m; j++) {
			cin >> x;
			cin >> y;
			
			if(hash.count(x) == 0) {
				count++;
				hash[x] = count;
				backup.push_back(x);
				tot++;
			} else {
				count = hash[x];
			}
			
			yes = 1;
			
			for (unsigned int g = 0; g < a[count].size(); g++) {
				if(a[count][g] == y) {
					yes = 0;
				}
			}
			if(yes) {
				a[count].push_back(y);
			}
			
			if(hash.count(y) == 0) {
				count++;
				hash[y] = count;
				backup.push_back(y);
				tot++;
			}

		}

		vector <int> yo(tot+5, 0);
		swap(visi, yo);
		
		for (unsigned int j = 0; j < backup.size(); j++) {
			if(visi[j] == white) {
				wow(backup[j]);
			}

			if(ok == 0) {
				break;
			}
		}

		if(ok) {
			cout << "Case "<<i<<": Yes\n";
		} else {
			cout << "Case "<<i<<": No\n";
		}
	}


}
