#include <bits/stdc++.h>
#define ll unsigned long long
#define MAX 100100

using namespace std;

int size = 5*1e6+10;

ll dp[5000010];

int prime[5000010];


ll euler(ll k)
{
	ll prod = k;
	ll den = 1;
	ll cnt  =0;
   for(int i = 2;i *i <= k;i++){

   		if( k % i ==0){
   			ll loc = i -1;
   			prod = prod*loc;
   			den = den*i;
   			cnt++;
   		}
   			while( k % i == 0){
   				k = k/i;
   			} 

   }

   if( k > 1)
   {
   	prod *= k-1;
   	den *= k;
   }

   	return prod/den;

}

ll sieve()
{

	ll i,j,k,m,n;

	for(i = 2; i <= 5000005;i++){
		if(prime[i] == 0){
			for(j =i*i; j < 5000005;j += i)
			{		
					if(prime[j] == 0)	
					prime[j] = i;
			}	
		}

	}



}

ll pregenerate()
{

	dp[1] = 1;
	
	dp[2]  = 1;


	sieve();

	for(int i= 3;i < (5*1e6) + 2;i++){

		if(prime[i] == 0)
			dp[i] = i-1;
		else {

			ll k=	prime[i];
	
		if( i/k % k == 0 )
			dp[i] = dp[i/k]*(k);
		else 
			dp[i] = dp[i/k]*(k-1);
		
		}

	
	}


	for(int i = 2; i <= size;i++ ){
		dp[i] = dp[i]*dp[i] + dp[i-1];
	}


}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("/home/sameer/sameer/sam.sam","r",stdin);
	#endif


	
	ll i,j,k,n,m,t,cont;
	
	
	scanf("%lld",&t);
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
