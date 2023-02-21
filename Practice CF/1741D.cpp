#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e9+7;
const ll INF=1e5+7;
const ll MIN=- 1e5+7;
void solve()
{
    ll n; cin>>  n;
    vector<ll> arr(n+5);
    map<ll , ll>mp;
    for(ll i = 1; i<=n; i++){
        cin>>arr[i];
        mp[arr[i]]++;
    }
    ll ans = 0;
    for(ll i=1 ;i<=n; i++){
        if(mp[-arr[i]]<=0){
            ans+=(-arr[i]);
            continue;
        }
        mp[-arr[i]] --;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //ll tc=1; cin>>tc;
    //for (ll t=1; t<=tc; t++) 
    solve();
    return 0;
}