/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll INF=3e5+7;
const ll MIN=- 1e10+7;
ll n, tree[INF*2];
void buid(){
    for(ll i=n-1;i>0;i--)
    tree[i] = max(tree[i<<1], tree[i<<1|1]);
}
void modify(ll id, ll vl){
    for(tree[id+=n] =vl; id>1;id>>=1){
        tree[id>>1] = max(tree[id] , tree[id^1]);
    }
}
ll getvl(ll l, ll r){
    ll res = MIN;
    for(l+=n, r+=n; l<r;l>>=1, r>>=1){
        if(l&1) res = max(res, tree[l++]);
        if(!(r&1)) res = max(res,tree[r--]);
    }
    if(l==r) res = max(res,tree[l]);
    return res;
}
void solve()
{
    cin>>n;
    for(ll i= 0;i<n;i++) cin>>tree[n+i];
    ll q; cin>>q;
    buid();
    while(q--){
        ll catego, x,y;
        cin>>catego>>x>>y;
        if(catego==1){
            x--,y;
            modify(x,y);
        }else{
            x--, y--;
            cout<<getvl(x,y)<<"\n";
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