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
ll tree[4*INF], arr[INF];
ll n; 
void update(int id, int l, int r, int lx, int rx){
    if(l>rx || lx>r) return;
    if(l==r){
        tree[id] = 1;
        return;
    }
    ll mid = (l+r)/2;
    update(id*2+1, l, mid, lx, rx);
    update(id*2+2, mid+1, r, lx, rx);
    tree[id] = tree[id*2+1] + tree[id*2+2];
}
ll getvl(int id, int l, int r, int lx, int rx){
    if(l>rx || lx>r) return 0;
    if(l>=lx && rx>=r) return tree[id];
    ll mid = (l+r)/2;
    return getvl(id*2+2, mid+1,r, lx, rx)+ getvl(id*2+1, l, mid, lx, rx);
}
void solve()
{
    cin>>n;
    for(int i=0;i<2*n;i++){
        cin>>arr[i];
    }
    vector<int>index(n+5), ans(n+5);
    for(int i=0;i<2*n;i++){
        if(index[arr[i]]!=0){
            ans[arr[i]] = i- (index[arr[i]]-1)-1 -getvl(0, 0, 2*n-1, index[arr[i]]-1, i)*2;
            update(0, 0, 2*n-1, index[arr[i]]-1,  index[arr[i]]-1);
        }else{
            index[arr[i]] = i+1;
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
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