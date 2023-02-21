/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+7,M =1e9+7;
ll lazy[N*4], tree[N*4], arr[N];
void buid(int id , int l, int r){
    if(l==r){
        tree[id]=arr[l];
        return;
    }
    int mid = (l+r)/2;
    buid(id*2, l, mid);
    buid(id*2+1, mid+1, r);
    tree[id] = max(tree[id*2], tree[id*2+1]);
    // cout<<tree[id]<<"\n";
}
void update(int id, int l, int r, int u, int v, int vl){
    if(lazy[id]!=0){
        tree[id]+=lazy[id];
        // cout<<tree[id]<<"\n";
        if(l!=r){
            lazy[id*2] +=lazy[id];
            lazy[id*2+1] +=lazy[id];
        }
        lazy[id]=0;
    }
    if(l>v || r<u) return;
    if(l>=u && r<=v){
        tree[id]+=vl;
        if(l!=r){
            lazy[id*2] += vl;
            lazy[id*2+1] += vl;
        }
        lazy[id] = 0;
        return;
    }
    int mid = (l+r)/2;
    update(id*2, l, mid, u,v, vl);
    update(id*2+1, mid+1, r, u,v, vl);
    tree[id] = max(tree[id*2], tree[id*2+1]);
    // cout<<tree[id]<<"\n";
}
ll get(int id, int l, int r, int u, int v){
    if(lazy[id]!=0){
        tree[id] += lazy[id];
        if(l!=r){
            lazy[id*2] += lazy[id];
            lazy[id*2+1] += lazy[id];
        }
        lazy[id] =0;
    }
    if(l>v || r<u) return -M;
    if(l>=u && r<=v){
        return tree[id];
    }
    ll mid = (l+r)/2;
    return max(get(id*2, l, mid, u, v), get(id*2+1, mid+1,r, u, v));
}
void solve()
{
    ll n, m,x,y,z,vl; cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    buid(1,1,n);
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>x;
        if(x==1){
            cin>>y>>z>>vl;
            // cout<<y<<z<<vl<<"\n";
            update(1,1,n,y,z,vl);
        }else{
            cin>>y>>z;
            // cout<<y<<z<<"\n";
            cout<<get(1,1,n, y,z)<<"\n";
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