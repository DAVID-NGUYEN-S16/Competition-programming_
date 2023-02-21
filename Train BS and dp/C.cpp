#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 1e6 + 7;
const ll INF = 1e18 + 7;

void solve()
{
    ll n; cin>>n;
    ll x[n+5], v[n+5];
    for(ll i = 1; i <= n; i++) cin>>x[i];
    for(ll i = 1; i <= n; i++) cin>>v[i];
    double l = 0, r = 1e9, m;
    for(ll i = 1; i <= 300; i++){
        m = (l+r)/2.0;
        double tmin = 1e9, tmax = -1e9;
        for(ll j = 1; j <= n; j++){
            tmin = min(tmin, x[j] + v[j]*m);
            tmax = max(tmax, x[j] - v[j]*m);
        }
        if(tmin <= tmax) l = m;
        else r = m;
    }
    printf("%.7lf", m);
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
}
