/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e9+7;
const ll INF=1e5;
const ll MIN=- 1e5+7;
void solve()
{
    ll n; cin>>n;
    ll x;
    vector<ll> cnt(n+5), dp(INF+5);
    ll idx = 0;
    for(ll i=1;i<=n;i++){
        cin>>x;
        cnt[x]++;
        idx = max(idx, x);
    }
    dp[0] = 0;
    dp[1] = cnt[1];
    for(ll i=2;i<=idx+4;i++){
        dp[i] = max(dp[i-1], cnt[i]*i+dp[i-2]);
        // cout<<dp[i]<<" ";
    }
    // cout<<"\n";
    cout<<dp[idx+4];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    //ll tc=1; cin>>tc;
    //for (ll t=1; t<=tc; t++) 
solve();
    return 0;
}