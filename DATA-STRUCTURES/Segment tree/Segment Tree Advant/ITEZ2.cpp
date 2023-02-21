/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll INF=3e5+7;
const ll MIN=- 1e5+7;
int n, tree[INF*2];
void modify(ll id, ll vl){
    for(tree[id+=n]=vl; id>1;id>>=1){
        tree[id>>1] = tree[id] + tree[id^1];
    }
}
ll getvl(ll l, ll r){
    ll res = 0;
    for( l+=n, r+=n;l<r; l>>=1, r>>=1 ){
        if(l&1) res += tree[l++];
        if(!(r&1)) res += tree[r--];
    }
    if(l==r) res+= tree[l];
    return res;
}
void solve()
{
    ll q;
    ll x, y, z;
    cin>>n>>q;
    while(q--){
        cin>>x>>y>>z;
        if(x==1){
            modify(y--,z);
        }else {
            ll ans= getvl(y--,z--);
            cout<<ans<<"\n";
        }
    }
}

int  main()
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