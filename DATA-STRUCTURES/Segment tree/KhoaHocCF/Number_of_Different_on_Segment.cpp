/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e9+7;
const ll INF=2e5+7;
const ll MIN=- 1e5+7;
struct Seg
{
    ll inv = 0;
    vector<ll>fre = vector<ll>(41,0);
    void merger(Seg a, Seg b){
        inv = a.inv + b.inv;
        for(ll i=1;i<=40;i++){
            if(a.fre[i] !=0 && b.fre[i]!=0) inv--;
            if(a.fre[i] !=0 || b.fre[i]!=0) fre[i] = 1;
        }
    }

}tree[INF*4];
ll arr[INF];
void buid(ll id, ll l, ll r){
    if(l>r) return;
    if(l==r){
        tree[id].inv=1;
        tree[id].fre[arr[l]] = 1;
        return;      
    }
    ll  mid = (l+r)/2;
    buid(id*2+1, l, mid);
    buid(id*2+2, mid+1, r);
    tree[id].merger(tree[id*2+1], tree[id*2+2]);
}


void update(ll id, ll l, ll r, ll idx, ll vl){
    if(l>idx || r<idx) return ;
    if(l==r){
        // tree[id].fre[arr[l]]=0;
        tree[id].inv=1;
        tree [id].fre = vector <ll> (41, 0);
        tree[id].fre[vl] = 1;
        return;
    }
    ll mid = (l+r)/2;
    update(id*2+1, l, mid, idx, vl);
    update(id*2+2, mid+1, r, idx, vl);
    tree[id].merger(tree[id*2+1], tree[id*2+2]);
}
Seg getvl(ll id, ll l, ll r, ll lx, ll rx){
    if(l>rx || r<lx) return Seg();
    if(l>=lx && r<=rx) return tree[id];
    ll mid = (l+r)/2;
    Seg ans;
    ans.merger(getvl(id*2+2, mid+1, r, lx, rx),getvl(id*2+1, l, mid, lx, rx));
    return ans;
}
void solve()
{
    ll n, m; cin>>n>>m;
    for(ll i=1;i<=n;i++) cin>>arr[i];
    buid(1, 1, n);
    while(m--){
        ll t, l, r; cin>>t>>l>>r;
        if(t==1){
            cout<<getvl(1,1,n,l, r).inv<<"\n";
        }else {
            update(1,1,n,l, r);
            arr[l] = r;
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