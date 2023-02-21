/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+7,M = 1e18;
ll tree[N*4], arr[N*4];
void buid(ll id , ll l, ll r){
    if(l==r){
        tree[id] = arr[r];
        return ;
    }
    int mid = (l+r)/2;
    buid(id*2,l,mid);
    buid(id*2+1,mid+1,r);
    tree[id] =max(tree[id*2],tree[id*2+1]);
}
void update(ll id, ll l, ll r, ll u){
    if(u<l|| u>r) return;
    if(l==r){
        tree[id] = arr[r];
        return;
    }
    ll mid = (l+r)/2;
    update(id*2, l,mid, u);
    update(id*2+1, mid+1, r,u);
    tree[id] = max(tree[id*2], tree[id*2+1]);
}
ll get(ll id, ll l, ll r, ll u, ll v){
    if(l>v|| r<u) return -M;
    if(l>=u && r<=v){
        return tree[id];
    }
    ll mid = (l+r)/2;
    return max(get(id*2, l, mid, u, v),get(id*2+1,mid+1,r, u, v));
}
void solve()
{
    ll n,k; cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    buid(1,1,n);
    ll mas = -M;
    for(int i = n-1;i>0;i--){
        // mas =max(mas,arr[i]);
        int l=0, r=0;
        l = i+1;
        r = i+k;
        if(r>n) r=n;
        ll t = max(get(1,1,n, l, r),(ll)0);
        // if(t<=0) continue;
        arr[i] = arr[i]+ t;
        update(1,1,n,i);
        // cout<<l<<"a"<<r<<"\n";
        // cout<<i<<" "<<arr[i]<<"\n";

        // mas =max(mas,arr[i]);
    }
    // cout<<arr[n]<<"\n";
    sort(arr+1, arr+n+1);
    if(arr[n]<0) cout<<0<<"\n";
    else cout<<arr[n]<<"\n";
    
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
