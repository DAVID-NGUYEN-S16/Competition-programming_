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
ll n, tree[4*INF], arr[INF];
void buid(int id, int l, int r){
    if(l>r) return;
    if(l==r) {
        tree[id] = 1;
        // cout<<tree[id]<<" "<<id<<"\n";
        return;
    }
    ll mid = (l+r)/2;
    buid(id*2+1, l, mid);
    buid(id*2+2, mid+1, r);
    tree[id] = tree[id*2+1]  + tree[id*2+2];
    // cout<<tree[id]<<" "<<id<<"\n";
}
ll getvl(int id, int l, int r, int k){
    if(l==r){
        tree[id] = 0;
        return l+1;
    }
    // cout<<id<<" "<<k<<" "<<tree[id*2+1]<<" "<<tree[id*2+2]<<" a\n";
    tree[id]--;
    ll mid = (l+r)/2;
    if(tree[id*2+1]>=k) return getvl(id*2+1, l,mid, k);
    else return getvl(id*2+2, mid+1, r, k-tree[id*2+1]);
}
void solve()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    buid(0, 0, n-1);
    ll N = n;
    ll ans[n+5];
    for(int i=n-1;i>=0;i--){
        ans[i] = getvl(0, 0, n-1, (N--)-arr[i]);
        // cout<<ans[i]<<"\n //////\n";
    }
    for(int i=0;i<n;i++) cout<< ans[i]<<" ";
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