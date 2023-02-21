/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e9+7;
const ll INF=1e17+7;
const ll MIN=- 1e5+7;
ll dp[1001][8];
void memsets(ll n){
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=8;j++){
            dp[i][j] = INF;
        }
    }
}
void solve()
{
    ll n; cin>>n;
    memsets(n);
    string s;
    ll price = 0;
    for(ll i=0;i<n;i++){
        cin>>price>>s;
        ll string_mask = 0;
        for(ll j = 0;j<3;j++){
            char cs = 'C' - j;
            bool have = 0;
            for(auto x: s) if(x==cs) have=1;
            if(have) string_mask += (1<<j);
        }
        dp[0][0]=0;
        for(ll mask=0;mask<8;mask++){
            dp[i+1][mask] = min(dp[i+1][mask], dp[i][mask]);
            dp[i+1][mask|string_mask] = min(dp[i+1][mask|string_mask], dp[i][mask]+price);
        }
    }
    if(dp[n][7]==INF) dp[n][7]=-1;
    cout<<dp[n][7];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //ll tc=1; cin>>tc;
    //for (ll t=1; t<=tc; t++) 
solve();
    return 0;
}