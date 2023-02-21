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
    ll n, m, x,y; cin>>n>>m;
    // int arr[n+5];
    vector<ll>v(n), prl(INF), prr(INF), arr(n+5);
    for(ll i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(ll i=1;i<=n;i++){
        if(arr[i]<=arr[i-1]) prl[i] = prl[i-1]+ abs(arr[i-1]- arr[i]);
        else prl[i] = prl[i-1];
        // cout<<prl[i]<<" -";
    }
    for(ll i=n;i>0;i--){
        if(arr[i]<=arr[i+1] ) prr[i] = prr[i+1] + abs(arr[i+1] -  arr[i]);
        else prr[i] = prr[i+1];
    }
    // cout<<"\n";
    while(m--){
        cin>>x>>y;
        if(x<=y) {
            cout<<abs(prl[y]- prl[x])<<"\n";
        }
        else{
            cout<<abs(prr[x] - prr[y])<<"\n";
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