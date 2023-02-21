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
ll tree[4*INF], arr[INF];
ll n; 
map<ll, ll>cnt[4*INF];
void process(ll id){
    if(tree[id*2+1]<tree[id*2+2]){
        tree[id]  = tree[id*2+1];
        cnt[id][tree[id]] = cnt[id*2+1][ tree[id]];
    }else{
        tree[id]  = tree[id*2+2];
        if(tree[id*2+1]==tree[id*2+2]) cnt[id][tree[id]] = cnt[id*2+1][tree[id]]+ cnt[id*2+2][tree[id]];
        else cnt[id][tree[id]]  = cnt[id*2+2][tree[id]];
    }
}
void buid(ll id, ll l, ll r){
    // cout<<id<<"\n";
    if(l>r) return;
    if(l==r) {
        tree[id] = arr[l];
        cnt[id][arr[l]] =1;
        return;
    }
    ll mid = (l+r)/2;
    buid(2*id+1,l, mid);
    buid(2*id+2,mid+1, r);
    process(id);
}
void update(ll id, ll l, ll r,ll lx, ll ry, ll x){
    if(l>ry || r<lx) return;
    if(l==r) {
        tree[id] = x;
        cnt[id][x]=1;
        return;
    }
    ll mid = (l+r)/2;
    update(2*id+1, l, mid, lx, ry,x);
    update(2*id+2, mid+1, r, lx, ry,x);
    process(id);
}

pair<ll,ll> getvl(ll id, ll l, ll r, ll lx, ll ry){
    if(l>ry||r<lx) return {MOD,MOD};
    if(l>=lx && r<=ry) return {tree[id],cnt[id][tree[id]]} ;
    ll mid = (l+r)/2;
    pair<ll,ll> nhanhl = getvl(id*2+1,l, mid, lx, ry), nhanh2 = getvl(id*2+2, mid+1, r, lx, ry);
    if(nhanhl.first>nhanh2.first) return nhanh2;
    else if(nhanhl.first<nhanh2.first) return nhanhl;
    else return {nhanh2.first, nhanh2.second+nhanhl.second };
}

void solve()
{
    ll q;
    cin>>n>>q;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    ll x,l, r;
    buid(0, 0, n-1);
    while(q--){
        cin>>x>>l>> r;
        if(x==1){
            // arr[l] = r;
            update(0,0, n-1, l, l,r);
            arr[l] = r;
        }else{
            cout<<getvl(0,0, n-1, l,r-1).first<<" "<<getvl(0,0, n-1, l,r-1).second<<"\n";
        }
    }
    //  for(ll i=0;i<9;i++)cout<<tree[i]<<" "<<cnt[i][tree[i]]<<"\n";
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