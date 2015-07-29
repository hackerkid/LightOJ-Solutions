#include <iostream>
#include <vector>
#include <stdio.h>
#define N 5000000
#include <string.h>
using namespace std;
unsigned long long ans[N+5];
bool isprime[N+5];

int prime()
{
	memset(isprime, 1, sizeof(isprime));

	for(int i = 2; i <= N; i++) {
		if(isprime[i] == 1) {
			for (int j = i + i; j <= N; j = j + i) {
				isprime[j] = 0;
			}

		}

	}


}


int  main()
{

	vector <int> x;
	ans[0] = 0;
	ans[1] = 0;

	int count = 0;
	unsigned long long a;
	unsigned long long b;
	unsigned long long temp;
	unsigned long long pr;
	unsigned long long t;
	unsigned long long j;
	unsigned long long div;
	prime();
	for (int i = 2; i <= N; i++) {
		if(isprime[i]) {
			x.push_back(i);
		}

	}
	
	for (int i = 0; i <= N; i++) {
		ans[i] = i;
	}
	for (int i = 0; i < x.size(); i++) {
		pr = x[i];
		div = 1;
		for (int j = pr; j <= N; j = j + pr) {
			ans[j] =(((ans[j] *  (pr - 1)))/ pr);
		}


		

	}

	for (int i = 1; i <= N; i++) {
			ans[i] = ans[i] * ans[i];
			ans[i] += ans[i-1];
	}
	cin >> t;

	for (int i =1 ; i <= t; i++) {
		scanf("%lld", &a);
		scanf("%lld", &b);
		temp = ans[b] - ans[a-1];
		printf("Case %d: %llu\n",i, temp); 
	}

}

				


&t);
	ll cases = t;

	pregenerate();




	while(t--){

		ll a,b;
	
	//	cin >> a >> b;	
		scanf("%lld %lld",&a,&b);

		ll ans = dp[b] - dp[a-1];

		// cout << "Case " << cases - t  << ": " <<  ans << endl;
		 printf("Case ");
		 printf("%lld: %llu\n",cases-t,ans);
		
		
	}



	return 0;
}
