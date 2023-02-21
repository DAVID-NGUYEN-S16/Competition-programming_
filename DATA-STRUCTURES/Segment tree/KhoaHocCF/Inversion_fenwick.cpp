/*=====================================================================================
                       IF YOU CAN POSSIBLE, THEN I ALSO CAN POSSIBLE
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e9+7;
const ll INF=1e5+7;
const ll MIN=- 1e5+7;
ll bit[INF], n;
void buid(int id, int vl){
    for(; id>0; id-=id&-id ) {
        bit[id]+=vl;
    }
}
// 0 1 1 0 3 
ll getvl(int id){
    ll sum = 0;
    for(;id<=n;id+=id&-id) sum+=bit[id];
    return sum;
}
void solve()
{
    cin>>n;
    int x;
    for(int i=1;i<=n;i++){
        cin>>x;
        cout<<getvl(x)<<" ";
        buid(x, 1);
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