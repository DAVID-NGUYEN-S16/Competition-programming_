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
void solve()
{
    ll n; cin>>n;
    ll x[n], y[n];
    for(ll i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    sort(x, x+n);
    sort(y, y+n);
    ll tb = n/2, tb1 = (n-1)/2;
    // cout<<tb<<" "<<tb1<<"\n";
    cout<<(x[tb]-x[tb1]+1) * (y[tb]-y[tb1]+1)<<"\n";

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) 
solve();
    return 0;
}