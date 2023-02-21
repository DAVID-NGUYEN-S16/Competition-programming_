#include<bits/stdc++.h>
using namespace std;
#define ll int
const ll MAX = 1e6 + 7;
const ll INF = 1e9 + 7;
ll dp[2][MAX];
ll arr[MAX];
ll n;
ll f(bool who, ll pos){
//    cout<<who<<" "<<pos<<endl;
    if(pos > n) return 0;
    if(dp[who][pos] != -1) return dp[who][pos];
    ll ans1 = INF, ans2 = INF;
    if(who){
        if(pos + 1 <= n) ans1 = arr[pos] + arr[pos+1] + f(0, pos+2);
        ans2 = arr[pos] + f(0, pos + 1);
    }else{
        if(pos+ 1 <= n) ans1 = f(1, pos + 2);
        ans2 = f(1, pos + 1);
    }

    return dp[who][pos] = min(ans1, ans2);
}
void solve()
{
     cin>>n;

    for(ll i = 1; i <= n; i++){
        cin>>arr[i];
    }
    for(int i = 0 ; i < 2; i++){
        for(int j = 0; j <= n; j++) dp[i][j] = -1;
    }
//    memset(dp, -1, sizeof(dp));
    cout<<f(1, 1)<<"\n";
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t; cin>>t;
    while(t--)
    solve();
}
