#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 1e6 + 7;
const ll INF = 1e18 + 7;
const ll MOD = 1e9 + 7;
void solve()
{
    ll n, a, b; cin>>n>>a>>b;
    ll ans = INF;
    ll x, y, r;
    for(ll i = 1; i <= n; i++){
        cin>>x>>y>>r;
        ll d = INF;
        if(x == a || y == b){
             d = sqrt((x- a)*(x - a) + (y- b)*(y - b)) - r  -1;
        }else d = sqrt((x- a)*(x - a) + (y- b)*(y - b)) - r;
        ans = min(ans, d);
    }
    cout<<ans;
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
