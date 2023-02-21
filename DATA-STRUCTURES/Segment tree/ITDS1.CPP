/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll INF=1e5+7;
const ll MAS=1e9+7;
ll a[INF*4], lazy[INF*4];
multiset<ll>tree[INF*4]; 
ll point[INF*4];
void buid (ll id, ll l, ll r){
    if(l>r) return;
    if(l==r){
        tree[id].insert(a[l]); 
        point[l] = id;
        return;
    }
    int mid = (l+r)/2;
    buid(id*2, l, mid);
    buid(id*2+1, mid+1, r);
    tree[id] = tree[id*2];
    for(auto x: tree[id*2+1]){
        tree[id].insert(x);
    }
}
void update(ll i, ll x){
    int id = point[i];
    int old = *tree[id].begin();
    while(id>0){
        tree[id].erase(tree[id].find(old));
        tree[id].insert(x);
        id = id/2;
    }
}
ll getvl(ll id, ll l, ll r,ll u, ll v, ll k){
    if(l > v || r < u) return MAS;
    if(l>=u && r<=v){
        auto ans = tree[id].lower_bound(k);
        if(ans==tree[id].end()) return MAS;
        else return *ans;
    }
    int mid = (l+r)/2;
    return min(getvl(id*2, l, mid, u, v, k), getvl(id*2+1, mid+1, r, u, v,k));
}
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    buid(1,1,n);
    while(m--){
        int check,l,r,k; cin>>check;
        if(check ==2){
            cin>>l>>r>>k;
            if(getvl(1,1,n, l, r,k)==MAS) cout<<"-1\n";
            else cout<<getvl(1,1,n, l, r,k)<<"\n";
        }else{
            cin>>l>>r;
            update(l, r);
        }
    }
    // for(auto x: tree[2]) cout<<x<<" "; 
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