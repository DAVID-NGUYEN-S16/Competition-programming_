/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e9+7;
const ll INF=1e5+7;
const ll MIN=- 1e5+7;
ll tree[4*INF], arr[INF];
void buid(ll id, ll l, ll r){
    if(l>r) return;
    if(l==r){
       if(arr[l]==1) tree[id] = 1;
       return;
    }
    ll mid = (l + r) /2;
    buid(id*2+1, l, mid);
    buid(id*2+2, mid+1, r);
    tree[id] = tree[id*2+1] + tree[id*2+2];
}
void update(ll id, ll idx, ll l, ll r){
    if(l>idx || r<idx) return;
    if(l==r){
        tree[id] = 1-tree[id];
        arr[l] = 1 - arr[l];
        return;
    }
    ll mid = (l + r)/2;
    update(id*2+1, idx, l, mid);
    update(2*id+2, idx, mid+1, r);
    tree[id] = tree[id*2+1] + tree[id*2+2];
}

ll getvl(ll id, ll &k, ll l, ll r, bool &check){
    // cout<<k<<" "<<id<<"\n";
    // cout<<l<<" "<<r<<"\n";
    if(tree[id]  <= k|| tree[id]==0) {
        // cout<<tree[id]<<" "<<k<<"del\n";
        k-=tree[id];
        return MOD;
    }
    if( check==false) return MOD;
    if(l==r){
        check=false;
        return l;
    }
    if(l>r ) return MOD;
    ll mid = (l+r)/2;
    // if()
    return min(getvl(id*2+2,k, mid+1, r, check),getvl(id*2+1, k, l, mid, check));
}
void solve()
{
    ll n, q;
    cin>>n>>q;
    for(ll i=0;i<n;i++) cin>>arr[i];
    buid(0, 0, n-1);
    while(q--){
        ll t,x; cin>>t>>x;
        bool check = true;
        if(t==1) update(0,x,0, n-1);
        else cout<<getvl(0, x, 0, n-1, check)<<"\n";
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