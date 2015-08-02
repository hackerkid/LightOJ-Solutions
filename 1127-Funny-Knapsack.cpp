#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;


long long n;
long long w;
long long inp[100];

vector <long long> a;
vector <long long> b;

long long create_a(long long i,long long sum, long long max)
{	
	if(sum > w) {
		return 0;
	}
	
	if( i == max) {
		a.push_back(sum);
		return 0;
	}

	create_a(i+1, sum + inp[i], max);
	create_a(i+1, sum,max);

}

long long create_b(long long i,long long sum, long long max)
{
	if(sum > w) {
		return 0;
	}
	if( i == max) {
		b.push_back(sum);
		return 0;
	}

	create_b(i+1, sum + inp[i], max);
	create_b(i+1, sum,max);

}


long long bs(long long j, long long k, long long targ)
{	
	long long i;

	i = (j + k) / 2;
	if(j > k) {
		return -1;
	}
	if((i == a.size() - 1 || a[i+1] > targ) and a[i] <= targ) {
		return i;
	}

	else {
		if(a[i] > targ) {
			return bs(j, i-1, targ);
		}

		else {
			return bs(i+1, k, targ);
		}

	}

}

 
int bs(long long val)
{
    int low = 0 , high =(int ) a.size() - 1 , mid , ans =low -1;
    while (low <= high ) {
        mid = (low + high ) >>1;
        if(a[mid] <= val) {
            ans = mid ;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ans ;
}


int main()
{	

	long long t;
	long long ans;

	scanf("%lld", &t);
	for (long long cs = 1; cs <= t; cs++) {

		scanf("%lld", &n);
		scanf("%lld", &w);
		ans = 0;
		long long k;
		vector <long long> ta;
		vector <long long> tb;

		swap(ta, a);
		swap(tb, b);

		for (long long i = 0; i < n; i++) {
			scanf("%lld", &inp[i]);
		}

		create_a(0, 0,  n/2);
		create_b(n/2, 0, n);

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		
		for (long long i = 0; i < b.size(); i++) {
			k = bs(0, a.size() -1, w - b[i]);
			ans = ans + k+1;
		}

		printf("Case %lld: %lld\n", cs, ans);


	}

}

