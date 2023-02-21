#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll MAX = 1e6 + 7;
const ll INF = 1e18 + 7;
const ll MOD = 1e9 + 7;
void solve()
{
    ll n, q;
    cin>>n
    vector<pair<ll,ll>> arr;
    ll x, y;
    for(int i = 0; i < n; i++){
        cin>>x>>y;
        arr.push_back({x, y});
    }
    ll ans = 0;
    for(int i = 1; i < (1<<n); i++){
        ll sumy = 0, masx = 0, misx = INF;
        for(int j  = 0; j < n; j++){
            if(i & (1<<j)){
                sumy+=arr[j].second;
                masx = max(masx, arr[j].first);
                misx = min(misx, arr[j].first);
            }
        }
        ans = max(ans, sumy - (masx - misx));
    }
    cout<<ans;

}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    solve();
    return 0;
}



