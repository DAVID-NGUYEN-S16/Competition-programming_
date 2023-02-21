/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define  c cout<<"yes"<<endl;
const ll MOD=1e9+7;
const ll INF=1e5+7;
const ll MIN=- 1e5+7;
void solve()
{
    ll n; cin>>n;
    ll a, b, cost; 
    // cin>>a>>b>>cost;
    // cout<<cost<<"\n";
    
    set<pair<int,int>>l, r;
    map<pair<int,int>, set<int>> mp;

    for(ll i=1;i<=n;i++){
        cin>>a>>b>>cost;
        l.insert({a,cost});
        r.insert({-b,cost});
        auto lef = *l.begin(), rig = *r.begin();
        int res = rig.second + lef.second;
        mp[{a, b}].insert(cost);
        if(mp[{lef.first, -rig.first}].size()!=0) {
            res = min(res, *mp[{lef.first, -rig.first}].begin() );
        }
        cout<<res<<"\n";
    }
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