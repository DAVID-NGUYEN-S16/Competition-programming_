/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+7, M= 1e9+5;
int tree[N*4], arr[N];
void update(int id, int l, int r, int x, int vl){
    if(l>x || r<x) return ;
    if(l==r){
         tree[id] = vl;
         return;
    }
    int mid = (l+r)/2;
    update(id*2,l, mid,x, vl);
    update(id*2+1, mid+1,r,x, vl);
    tree[id] = tree[id*2]+ tree[id*2+1];
    // cout<<tree[id]<<"\n";
}
long long get(int id, int l, int r, int u, int v){
    if(l>v || r<u) return 0;
    if(l>=u && r<=v) return tree[id];
    int mid = (l+r) /2;
    return get(id*2, l, mid, u,v)+ get(id*2+1,mid+1,r, u, v);
}
void solve()
{
    int n,x,y,z,m; cin>>n>>m;
    for(int i = 1;i<=m;i++){
        cin>>x;
        if(x==1){
            cin>>y>>z;
            update(1,1,n,y,z);
        }else{
            cin>>y>>z;
            cout<<get(1,1,n,y,z)<<"\n";
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