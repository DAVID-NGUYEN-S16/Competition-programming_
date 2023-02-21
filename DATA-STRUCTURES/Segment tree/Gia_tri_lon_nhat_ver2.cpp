/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+7;
int tree[N*4], arr[N];
void update (int id, int l, int r, int u, int v,int k){
     if(l>v || r<u){
         return ;
     }
     if(l==r){
         tree[id] +=k;
        //  cout<<tree[id]<<" "<<id<<"\n";
        //  cout<<id<<"a\n";
         return ;
     }
     int mid = (l+r)/2;
     update(id*2, l, mid,u,v, k);
     update(id*2+1, mid+1,r,u,v,k);
     tree[id] = max(tree[id*2], tree[id*2+1]);
    //  cout<<tree[id]<<"\n";
    // cout<<id<<"\n";
}
int get(int id, int l, int r , int u, int v){
    if(l>v || r<u){
         return -N;
     }
     if(l>=u && r<=v){
         return tree[id];
     }
     int mid = (l+r)/2;
     return max(get(id*2,l,mid,u,v), get(id*2+1,mid+1,r,u,v));
}
void solve()
{
    // for(int i=1;i<=10;i++) cout<<tree[i];
    int n,t,x,y,k, query;
    cin>>n>>query;
    while(query--){
        cin>>t;
        if(t==0){
            cin>>x>>y>>k;
            update(1,1,n,x,y,k);
        }else{
            cin>>x>>y;
            cout<<get(1,1,n,x,y)<<"\n";
        }
    }
    // cout<<tree[4]<<" "<<tree[5]<<" "<<tree[8]<<" "<<tree[9];
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