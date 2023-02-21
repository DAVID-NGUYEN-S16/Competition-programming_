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
    int  n, a, b; cin>>n>>a>>b;
    vector<int>v;
    int l= a;
    for(int i=1;i<=n;i++){
        int ans = (l+i-1)/i;
        if(ans*i<=b){
            v.push_back(ans*i);
        }else{
            cout<<"NO\n"; return;
        }
    }
    cout<<"YES\n";
    for(auto x: v) cout<<x<<" ";
    cout<<"\n";
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