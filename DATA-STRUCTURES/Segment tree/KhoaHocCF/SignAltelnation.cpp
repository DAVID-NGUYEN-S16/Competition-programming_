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
ll  arr[INF], n;
struct SignAltelnation
{
    ll even=0, odd=0;
}tree[INF*4];

void update(ll id, ll l, ll r, ll idx, ll vl){
    if(l>idx || r<idx) return;
    if(l==r){
        if(l%2==0) tree[id].even = vl;
        else tree[id].odd = vl;
        return;
    }
    ll mid = (l+r)/2;
    update(id*2+1, l, mid, idx, vl);
    update(id*2+2, mid+1, r, idx, vl);
    tree[id].even = tree[id*2+1].even + tree[id*2+2].even;
    tree[id].odd = tree[id*2+1].odd + tree[id*2+2].odd;
}
void buid(ll id, ll l, ll r){
    if(l>r) return;
    if(l==r){
         if(l%2==0) tree[id].even = arr[l];
        else tree[id].odd = arr[l];
        return;
    }
    ll mid = (l+r)/2;
    buid(id*2+1, l, mid);
    buid(id*2+2, mid+1, r);
    tree[id].even = tree[id*2+1].even + tree[id*2+2].even;
    tree[id].odd = tree[id*2+1].odd + tree[id*2+2].odd;
}
SignAltelnation getvl(ll id, ll l, ll r, ll lx , ll rx){
    SignAltelnation ans;
    if(l>rx || r<lx) return ans;
    if(l>=lx && r<=rx){
        return tree[id];
    }
    ll mid = (l+r)/2;
    SignAltelnation res1 = getvl(id*2+2, mid+1, r, lx, rx) , res2 = getvl(id*2+1, l, mid, lx, rx);
    ans.even = res1.even  + res2.even;
    ans.odd = res1.odd + res2.odd;
    return ans;
}
void solve()
{
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>arr[i];
        // if(i%2==0) arr[i] = -arr[i];
    }
    buid(1,1, n);
    ll q; cin>>q;
    while(q--){
        ll t, l, r; cin>>t>>l>>r;
        if(t==0){
            // if(l%2==0) r =-r;
            update(1,1, n, l, r);
            // arr[l] = r;
        }else {
            SignAltelnation ans = getvl(1, 1, n, l, r);
            // cout<<getvl(1, 1, n, l, r)<<"\n";
            if(l%2==0) cout<<ans.even - ans.odd<<"\n";
            else cout<<ans.odd - ans.even<<"\n";
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