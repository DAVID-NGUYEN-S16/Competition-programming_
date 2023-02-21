/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e9+7;
const ll INF=1e5+7;
const ll MIN=- 1e5+7;
void solve()
{
    ll  n, k; cin>>n>>k;
    vector<ll>pre(n+5),sumpre(n+5),arr(n+5), state(n+5);
    for(ll i=1;i<=n;i++) cin>>arr[i];
    for(ll i=1;i<=n;i++){
        cin>>state[i];
        if(state[i]==1) pre[i] = pre[i-1]+ arr[i];
        else pre[i] = pre[i-1];
        sumpre[i] = sumpre[i-1] + arr[i];
        // cout<<pre[i]<<" ";
    }
    // cout<<"\n";
    // for(ll i=1;i<=n;i++){
    //     cout<<sumpre[i]<<" ";
    // }
    // cout<<"\n";
    ll ans = 0;
    for(ll i=1;i<=n-k+1;i++){
        ans = max(ans, pre[i-1]+ sumpre[i+k-1] - sumpre[i-1] + pre[n] - pre[i+k-1] );
        // cout<<sumpre[i+k-1] <<" "<<i+k-1<<"\n";
    }
    cout<<ans<<"\n";
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