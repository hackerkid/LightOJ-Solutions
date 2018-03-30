//  amiD
#include <bits/stdc++.h>
#define ld long double
#define ll long long int
#define mod 1000000007
#define ll_inf 1000000000000000
#define int_inf 1000000000
#define pb push_back
#define endl '\n'
#define Endl '\n'
#define eps 1e-9
#define PI acos(-1.0)
#define ii pair<int,int>
#define se second
#define fi first
using namespace std;
bool vis[505][505];
double dp[502][505];
double cal(int red, int blue){
    if(red==0){
        if(blue%2==0)return dp[red][blue]=0.0;
        return dp[red][blue]= 1.0;
    }
    if(blue==0)return dp[red][blue]=0.0;
    if(blue<=0)return 0.0;
    double &ret=dp[red][blue];
    if(vis[red][blue])return dp[red][blue];
    vis[red][blue]=1;
    ret=1.0;
    ret=((1.0*red)/(red+blue)*cal(red-1, blue-1));
    if(blue>=2)ret+=((1.0*blue)/(red+blue)*cal(red, blue-2));
    return ret;
}
int main(){
    cout.precision(12);
    int t, ca=1;
    cin>>t;
    while(t--){
        int red,blue;
        scanf("%d%d",&red, &blue);
        printf("Case %d: %.8f\n", ca++, cal(red, blue));
    }
}
