#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
#include <math.h>
using namespace std;



long long abs(long long x)
{
	if(x < 0)
		return x * -1;

	return x;

}

int main()
{

	int t;
	int n;
	int d;
	long long x;
	long long small;
	
	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &n);
		scanf("%d", &d);
		small = 0;

		priority_queue  < pair<long long, int>,	vector <pair < long long , int> >, greater <pair < long long, int> > > bigq;
		priority_queue <pair <long long, int> > smallq;
		
		for (int i = 1; i <= n; i++) {
			cin >> x;
			//cout << x << "time -> :"<<i <<endl;
			bigq.push(make_pair(x, i));
			smallq.push(make_pair(x, i));

			while(!bigq.empty() and (i - bigq.top().second) >= d) {
				//cout << " poping bigq " << bigq.top().first << endl;
				bigq.pop();
			}
			
			while(!smallq.empty() and(i - smallq.top().second) >= d) {
				//cout << " poping smallq " << smallq.top().first << " " << smallq.top().second<<endl;
				smallq.pop();
			}

			if(bigq.size() >= 2 and smallq.size() >= 2) {
				small = max(small, abs(bigq.top().first - smallq.top().first));
				//cout << "small updated "<< small <<endl;;
			}

		}

		printf("Case %d: %lld\n", cs, small);

	}



}

			
			



