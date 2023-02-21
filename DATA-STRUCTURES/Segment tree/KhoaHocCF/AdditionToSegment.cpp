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
ll tree[4*INF], arr[INF], lazy[INF*4], n;
void check(ll id, ll l, ll r){

    if(lazy[id]!=0){
        tree[id]+=lazy[id];
        if(l!=r){
            lazy[id*2+1] += lazy[id];
            lazy[id*2+2] += lazy[id];
        }
        lazy[id]= 0;
    }
}
void update(ll id, ll l, ll r, ll lx, ll rx, ll vl){
    // cout<<l<<" "<<r<<"\n";
    if(l>rx || r<lx) return;
    check(id, l, r);
    // cout<<id<<"\n";
    
    if(l>=lx && r<=rx){
        tree[id]+=vl;
        if(l!=r){
            lazy[id*2+1]+=vl;
            lazy[id*2+2]+=vl;
        }
        return;
    }
    ll mid = (l+r)/2;
    update(id*2+1, l, mid, lx, rx, vl);
    update(id*2+2, mid+1,r, lx, rx, vl);
    tree[id] = tree[id*2+1] + tree[id*2+2];

}
ll getvl(ll id, ll l, ll r, ll idx){
    // cout<<l<<" "<<r<<"\n";
    if(l>idx || r<idx) return 0;
    check(id, l, r);
    if(l==r){
        return tree[id];
    }
    ll mid = (l+r)/2;
    return getvl(id*2+2, mid+1, r, idx) + getvl(id*2+1, l, mid, idx);
}
void solve()
{
    ll q;
    cin>>n>>q;
    // for(ll i=0;i<n;i++) cin>>arr[i];
    while(q--){
        ll t, l, r, v;
        cin>>t;
        if(t==1){
            cin>>l>>r>>v;
            // c
            update(0, 0, n-1, l, r-1, v);
        }else {
            cin>>l;
            cout<<getvl(0, 0, n-1, l)<<"\n";
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