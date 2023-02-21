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
ll minelement(ll arr[], ll n ){
    ll mins = arr[1];
    for(ll i=1;i<n;i++) mins = min(arr[i], mins);
    return mins;
}
ll maxelement(ll arr[], ll n ){
    ll mins = 0;
    for(int i=2;i<=n;i++) mins = max(arr[i], mins);
    return mins;
}
void solve()
{
    ll n; cin>>n;
    ll arr[n+5];

    for(ll i=1;i<=n;i++){
        cin>>arr[i];
        
    }
    ll ans =0;
    arr[0] = arr[n];
    for(int i=1;i<=n;i++) {
        ans = max(ans, arr[i-1]-arr[i]);
    }
    ans = max({ans,arr[n] - minelement(arr, n), maxelement(arr,n)-arr[1]});
    cout<<ans<<"\n";
    
    // cout<<ans
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) 
    solve();
    return 0;
}