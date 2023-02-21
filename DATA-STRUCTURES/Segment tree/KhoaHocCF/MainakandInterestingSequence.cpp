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
    ll n, m; cin>>n>>m;
    if(m<n || (n%2==0 && m%2!=0)) cout<<"No\n";
    else{
        int x = m/n, du = m%n, i=1;
        cout<<"Yes\n";
        vector<int>ans;
        for(int i=1;i<=n-2;i++){
            cout<<1<<" ";
        }
        if(n%2==0) cout<<(m-n+2)/2<<" "<<(m-n+2)/2<<" \n";
        else {
            if(n>1) cout<<1<<" "<<m-n+1;
            else cout<<m-n+1;
        }
        cout<<"\n";
    }

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