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
void solve()
{
    int n, k; cin>>n>>k;
    string s; cin>>s;
    vector<int>pre(n+5);
    for(int i=1;i<=n;i++ ){
        if(s[i-1]=='B') pre[i] = pre[i-1]+1;
        else  pre[i] = pre[i-1];
    }
    int ans = INF;
    for(int i=1;i<=n-k + 1;i++){
        ans = min(ans, k - (pre[i+k-1]-pre[i-1]));
        // cout<< pre[i+k-1]<<" "<<pre[i-1]<<"\n";
    }
    if(ans == INF) ans = 0;
    cout<<ans<<"\n";
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