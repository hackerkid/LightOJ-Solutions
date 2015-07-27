#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>
#include <sstream>
using namespace std;
map <int, vector <string> > q;
int mod = 16127;

int getHash(string line)
{
	int hash;

	hash = 1;
	for (int j = 0; j < line.length(); j++) {
		hash = hash * ( 1 +line[j] - 'A');
		hash = hash % mod;
	}
	//cout << line << " " << hash << endl;
	return hash;

}

bool check(string a, string b)
{
	int n;
	int acount[70];
	int bcount[70];

	
	memset(acount, 0, sizeof(acount));
	memset(bcount, 0, sizeof(bcount));

	n = a.length();

	if(a.length() != b.length()) {
		return 0;
	}

	if(a.length() == 1) {
		return a[0] == b[0];
	}

	if(a.length() == 2) {
		return a[0] == b[0] and a[1] == b[1];
	}

	if(a[0] != b[0] or a[n-1] != b[n-1]) {
		return 0;
	}
	for (int i = 1; i < n-1; i++) {
		acount[a[i] - 'A']++;
		bcount[b[i] - 'A']++;
	}

	for (int i = 0; i < 56; i++) {
		if(acount[i] != bcount[i]) {
			return 0;
		}

	}

	return 1;

}

int getCount(string a)
{
	int hash;
	int count;

	count = 0;
	hash = getHash(a);

	for (int i = 0; i < q[hash].size(); i++) {
		if(check(a, q[hash][i])) {
			count++;
		}

	}

	return count;

}


bool calculate(string line)
{
	istringstream iss(line);
   	string a;
   	long long ans;
   	long long count;
   	ans = 1;
   	
   	while(iss >> a) {
		count = getCount(a);
		ans = ans * count;

	}

	printf("%lld\n", ans);

}

int mmain()
{
	string x;
	int hash;
	x = "AZbcdZ abczzz lfdpPSlslaSPApSWlwLWWWsssss lfdpPSlslaSAPpSWlwLWWWsssss ";

	string temp[] = {"abczzz", "AbcdZZ","lfdpPSlslaSPApSWlwLWWWsssss"};
	for (int i = 0; i < 3; i++) {
		hash = getHash(temp[i]);
		q[hash].push_back(temp[i]);
	}

	calculate(x);
}
int main()
{

	int m;
	char temp[100008];
	int t;
	int dic_count;
	long long hash;
	long long ans;
	int count;
	string line;

	
	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%d",&dic_count); 
		map <int, vector <string> > tq;
		swap(q, tq);

		gets(temp);
		for (int i = 0; i < dic_count; i++) {
			gets(temp);
			line = temp;
			hash = getHash(line);
			q[hash].push_back(line);

		}

		scanf("%d", &m);
		gets(temp);
		printf("Case %d:\n", cs);
		for (int i = 0; i < m; i++) {
			ans = 1;
  			
   			gets(temp);
			line = temp;
			calculate(line);


   		}


	}


}


