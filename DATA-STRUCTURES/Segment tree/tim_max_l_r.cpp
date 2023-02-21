/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+7;
int tree[N*4];
int a[N];
int update(int id,int l,int r, int u,int v){
    if(l>v || r<u) return -N;
    if(l>=u && r<=v){
        return tree[id];
    }
    int mid = (l+r)/2;
    return max(update(id*2,l,mid,u,v), update(id*2+1,mid+1, r,u,v));
}
void build(int id, int l , int r){
    if (l==r) {
        tree[id] = a[r];
        return ;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    tree[id] = max(tree[id*2],tree[id*2+1]);
    // cout<<id<<" "<<tree[id]<<"\n";
}
void solve()
{
    int n; cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    int l,r; cin>>l>>r;
    cout<<update(1,1,n,l,r);
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