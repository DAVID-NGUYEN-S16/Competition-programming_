#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 1e6 + 7;
const ll INF = 1e18 + 7;
const ll MOD = 1e9 + 7;
ll arr[MAX], brr[MAX], crr[MAX], tree[MAX*4];
void build(ll id, ll l, ll r){
    if(l == r){
        tree[id] = crr[l];
        return;
    }
    ll mid = (l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    tree[id] = __gcd(tree[id*2], tree[id*2+1]);
}
ll getvl(ll id, ll l ,ll r, ll lx, ll rx){
    if(l > rx || r < lx) return 0;
    if(l >= lx && r <= rx) return tree[id];
    ll mid = (l+r)/2;
    return __gcd(getvl(id*2, l, mid, lx, rx), getvl(id*2+1, mid+1, r, lx, rx));
}
void solve()
{
    ll n, q; cin>>n>>q;
    for(ll i = 1; i <= n; i++) cin>>arr[i];
    for(ll i = 1; i <= n; i++) cin>>brr[i];
    for(ll i = 1; i <= n; i++) crr[i] = abs(arr[i] - brr[i]);
    build(1, 1, n);
    while(q--){
        ll l , r; cin>>l>>r;
        cout<<getvl(1, 1, n, l, r)<<"\n";

    }





}
/*
16 2 2 2 10
1 2
3 4
5 6
7 8
5 6
7 8
5 6
7 8
1 2
3 4
5 6
7 8
5 6
7 8
5 6
7 8
1 2
3 4
5 6
7 8
5 6
7 8
5 6
7 8
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


