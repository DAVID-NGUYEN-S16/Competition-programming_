#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 1e6 + 7;
const ll INF = 1e18 + 7;
const ll MOD = 1e9 + 7;
ll k, n, u, v , s;
struct matrix{
    ll m[101][101];
    void clears(ll n){
        for(ll i = 1; i <= n; i++)
            for(ll j = 1; j <= n; j++) m[i][j] = 0;
    }

};
ll binmul(ll a, ll b){
    ll res = 0;
    while(b){
        if(b&1) res=  (res + a) %s;
        a = (a+a) % s;
        b >>=1;
    }
    return res;
}
void solve()
{
    cin>>k>>n>>u>>v>>s;
    matrix ans, x;
    ans.clears(n);
    x.clears(n);

    for(ll i = 1; i <= n; i++)
        for(ll j = 1; j <= n; j++)
            cin>>ans.m[i][j];
    k--;
    while(k--){
        for(ll i = 1; i <= n; i++)
            for(ll j = 1; j <= n; j++){
                cin>>x.m[i][j];
                x.m[i][j] %= s;
                if(x.m[i][j] < 0) x.m[i][j] = (x.m[i][j] + s) % s;
            }
        matrix res;
        res.clears(n);
        for(ll i = 1; i <= n; i++){
            ll p = ans.m[u][i] % s;
            if(p < 0) p= (p + s) % s;
            for(ll j = 1; j <= n; j++){
                res.m[u][j] += binmul(p, x.m[i][j]);
                res.m[u][j]%=s;
            }
        }
        ans = res;
    }
    cout<<ans.m[u][v]%s;


}
/*
3 2 1 2 10
1 2
3 4
5 6
7 8
5 6
7 8
5 6
7 8
*/
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    solve();
}

