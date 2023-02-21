#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 1e6 + 7;
const ll INF = 1e18 + 7;
ll n, m;
ll tower[MAX], cl[MAX];
bool ok(ll mid){
        bool ch = 1;

        for(ll i = 1; i <= n; i++){
            ll id = lower_bound(cl + 1, cl + m + 1, tower[i]) - cl;
            if(id > m){
                if(cl[m] + mid < tower[i]) {
                        return false;
                }
            }else {
                ll s1 = cl[id] - mid;
                ll s2 = cl[id-1] + mid;
                int th1 = 0, th2 = 0;
                if(id - 1 == 0 ) s2 = 0;
                if(tower[i] >= s1){
                    th1 = 1;
                }
                if(tower[i] <= s2 && id - 1 != 0){
                    th2 = 1;
                }

                ch = (th1 | th2);
                if(ch == false) return false;
            }

        }
        return true;
}
void solve()
{
     cin>>n>>m;

    for(ll i = 1; i <= n; i++){
        cin>>tower[i];
    }
    sort(tower + 1,  tower + n + 1);
    for(ll i = 1; i <= m; i++){
        cin>>cl[i];
    }
    ll l = 0, r = INF;
    ll ans = INF;
    while(l <= r)
    {
        ll mid = (l+r)/2;
        if(r - l == 1){
            if(ok(l)){
                ans = min(ans, l);
                break;
            }
        }
        if(r==l){
            if(ok(l)){
                ans = min(ans, l);
            }
            break;
        }

        if(ok(mid)){
                ans = min(ans,mid);
                r = mid ;
        }else {
                l = mid + 1;
        }
    }
    cout<<ans<<"\n";

}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
}
