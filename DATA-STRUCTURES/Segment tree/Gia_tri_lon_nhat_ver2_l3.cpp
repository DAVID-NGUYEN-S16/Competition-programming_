/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll INF=1e5+7;
const ll MIN=- 1e5+7;
int lazy[INF*4], tree[INF*4];
void update(int id, int l, int r, int u, int v,  int k){
    if(lazy[id]!=0){
        tree[id]+=lazy[id];
        if(l!=r){
            lazy[id*2]+=lazy[id];
            lazy[id*2+1]+=lazy[id];
        }
        lazy[id]=0;
    }
    if(l>=u && r<=v){
        tree[id]+=k;
        if(l!=r){
            lazy[id*2]+=k;
            lazy[id*2+1]+=k;
        }
        lazy[id]=0;
        return;
    }
    if(l>v || r<u) return;
    int mid = (l+r)/2;
    update(id*2, l, mid, u,v, k);
    update(id*2+1, mid+1, r, u, v,k);
    tree[id] = max(tree[id*2], tree[id*2+1]);
}
int getvl(int id, int l, int r, int u, int v){
    if(lazy[id]!=0) {
        tree[id]+=lazy[id];
        if(l!=r){
            lazy[id*2]+=lazy[id];
            lazy[id*2+1]+=lazy[id];
        }
        lazy[id] = 0;
    }
    if(l>v || r<u) return 0;
    if(l>=u && r<=v) return tree[id];
    int mid = (l+r)/2;
    return max(getvl(id*2,l, mid, u, v), getvl(id*2+1, mid+1, r, u, v));
}
void solve()
{
    int n,q; cin>>n>>q;
    int check, l, r, k;
    while(q--){
        cin>>check;
        if(check) {
            cin>>l>>r;
            cout<<getvl(1, 1, n, l, r)<<"\n";
            
        }else{
            cin>>l>>r>>k;
            update(1, 1, n, l, r, k);
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