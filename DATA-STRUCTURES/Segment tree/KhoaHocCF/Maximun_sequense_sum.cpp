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
struct seg
{
    ll pref, suf, sum, ans;
    void assign(ll prefs, ll sufs, ll sums, ll anss){
        pref = prefs;
        suf = sufs;
        sum = sums;
        ans = anss;
    }
}tree[INF*4];
ll arr[INF], n;
void pro(int id){
    ll pref = max(tree[id*2+1].pref,tree[id*2+1].sum + tree[id*2+2].pref);
    ll suf = max(tree[id*2+2].sum + tree[id*2+1].suf, tree[id*2+2].suf);
    ll sum = tree[id*2+1].sum+ tree[id*2+2].sum;
    ll ans = max({tree[id*2+1].ans, tree[id*2+2].ans, tree[id*2+1].suf + tree[id*2+2].pref});
    tree[id].assign(pref, suf, sum, ans);
}
void buid(ll id, ll l, ll r){
    // cout<<id<<"\n";
    if( l > r ) return;
    if(l==r){
        if(arr[l]>0) {
            tree[id].assign(arr[l],arr[l],arr[l],arr[l]);
        }
        else tree[id].assign(0,0,arr[l], 0);
        return;
    }
    ll mid = ( l + r )/2;
    buid(id*2+1, l, mid);
    buid(id*2+2, mid+1, r);
    pro(id);
}
void update(ll id, ll l, ll  r, ll lx, ll rx, ll value){
    if( l > rx|| r < lx) return;
    if(l==r){
        if(value>0) tree[id].assign(value,value,value,value);
        else tree[id].assign(0,0,value, 0);
        return;
    }
    ll mid = ( l + r )/2;
    update(id*2+1, l, mid, lx, rx, value);
    update(id*2+2, mid+1, r,lx, rx, value);
    pro(id);
}
void solve()
{
    ll q;
    cin>>n>>q;
    for(ll i=0; i< n; i++) cin>> arr[i];
    buid(0, 0, n-1);
    cout<<tree[0].ans<<"\n";
    ll i, v;
    while(q--){
        cin>>i>>v;
        update(0, 0, n-1, i, i, v);
        cout<<tree[0].ans<<"\n";
    }

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //ll tc=1; cin>>tc;
    //for (ll t=1; t<=tc; t++) 
    solve();
    return 0;
}