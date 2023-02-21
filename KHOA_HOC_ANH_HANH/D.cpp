#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e9+7;
const ll INF=1e5+7;
const ll MIN=- 1e5+7;
int a, b;
ll sum(ll n){
    if(n<=0) return 0;
    ll s = 0;
    if(n%2==0) s+= (n*n)/4;
    else s+= (n+1) *(n+1)/4;
    return s+ sum(n/2);
}
void solve()
{
    cin>>a>>b;
    
    cout<<sum(b) - sum(a-1)<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    freopen("odddiv.inp", "r", stdin);
    freopen("odddiv.out", "w", stdout);
    // #endif
    //     freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //ll tc=1; cin>>tc;
    //for (ll t=1; t<=tc; t++) 
    solve();
    return 0;
}