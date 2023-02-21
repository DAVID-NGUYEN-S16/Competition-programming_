/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+7;
int tree[N*4];
struct KQUERYK2
{
    int i, j, k, id, vl;
}query[N*4];
vector<pair<int,int>> arr(N*4);
bool cmp(const KQUERYK2 &a, const KQUERYK2 &b){
    return a.k<b.k;
}
bool cmp1(const KQUERYK2 &a, const KQUERYK2 &b){
    return a.id<b.id;
}
void update(int id, int l, int r, int u){
    if(l>u || r<u) return;
    if(l==r){
       tree[id]=0;
       return;
    }
    int mid = (l + r)/2;
    update(id*2,l, mid, u);
    update(id*2+1,mid+1,r,u);
    tree[id] = tree[id*2] +  tree[id*2+1];
}
void buid(int id, int l, int r){
    if(l==r) {
        tree[id] = 1;
        return;
    }
    int mid = (l+r)/2;
    buid(id*2, l,mid);
    buid(id*2+1, mid+1,r);
    tree[id] = tree[id*2] + tree[id*2+1];
}
int get(int id, int l, int r, int u, int v){
    if(l>v|| r<u) return 0;
    if(l>=u && r<=v) return tree[id];
    int mid = (l+r)/2;
    return get(id*2, l, mid, u,v)+get(id*2+1, mid+1, r,u,v);
}
void solve()
{
    int n,m; cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>arr[i].first;
        arr[i].second = i;
    }
    cin>>m;
    sort(arr.begin()+1,arr.begin()+n+1);
    for(int i = 1;i <= m; i++) {
        cin>>query[i].i>>query[i].j>>query[i].k;
        query[i].id = i;
    }
    sort(query+1, query+m+1, cmp);
    int ids = 1;
    buid(1,1,n);
    for(int i = 1; i<=n ;i++){
         if(arr[i].first<=query[ids].k){
              update(1,1,n,arr[i].second);
         }else{
              query[ids].vl = get(1,1,n,query[ids].i, query[ids].j);
              ids++;
              i--;

         }
         if(ids>m) break;
    }
    sort(query+1,query+m+1,cmp1);
    for(int i=1;i<=m;i++) cout<<query[i].vl<<"\n";

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