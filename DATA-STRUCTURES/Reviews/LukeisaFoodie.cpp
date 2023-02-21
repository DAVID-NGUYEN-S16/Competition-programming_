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
    ll n, x; cin>>n>>x;
    ll cost = 0, l, r;
    vector<ll > arr(n+5);
    for(ll i=1;i<=n;i++) cin>>arr[i];
    l = arr[1]-x;
    r = arr[1]+x;
    for(ll i=2;i<=n;i++){
        if(arr[i]+x<l || arr[i]-x>r){
            cost++;
            l = arr[i] - x;
            r = arr[i] + x;
        }else {
            l = max(l,arr[i]-x);
            r = min(r, arr[i]+x);
        }
    }
    cout<<cost<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) 
solve();
    return 0;
}