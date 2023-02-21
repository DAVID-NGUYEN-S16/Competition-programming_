/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e9+7;
const ll INF=1e5+7;
const ll MIN=- 1e5+7;
ll n, arr[INF], tree[9*100000 +5], dpl=0; 
void buid(ll id, ll l, ll r){
    if(l>r) return;
    if(l==r) {
        tree[id] = arr[l];
        return;
    }
    ll mid = (l+r)/2;
    buid(id*2+1, l, mid);
    buid(id*2+2, mid+1, r);
    tree[id] = max(tree[id*2+1], tree[id*2+2]);
}
void update(ll id, ll l, ll r, ll idx, ll vl){
    if(l>idx || r<idx) return;
    if(l==r){
        tree[id] = vl;
        return;
    }
    ll mid = (l+r)/2;
    update(id*2+1, l, mid, idx, vl);
    update(id*2+2, mid+1, r, idx, vl);
    tree[id] = max(tree[id*2+1],tree[id*2+2]);
}
ll getvl(ll id, ll l, ll r,ll vl, int mins){
    if(tree[id]<vl||dpl==1||l>r||r<mins) return MOD;
    // if(l>r) return MOD;
    if(l==r ) {
        dpl=1;
        return l;
    }
    ll mid = (l+r)/2;
    return min(getvl(2*id+2, mid+1,r, vl, mins),getvl(id*2+1,l, mid, vl, mins));
}
void solve()
{
    ll q;
    cin>>n>>q;
    for(ll i=0;i<n;i++) cin>>arr[i];
    buid(0,0, n-1);
    while(q--){
        ll i, v, vl;
        cin>>i>>v>>vl;
        if(i==1) {
            update(0, 0, n-1, v, vl);
        }else {
            dpl=0;
            ll ans =  getvl(0,0, n-1, v, vl);
            if(ans==MOD) cout<<"-1\n";
            else cout<<ans<<"\n";
        }
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