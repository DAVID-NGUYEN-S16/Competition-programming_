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
    int n; cin>>n;
    int arr[n+5];
    arr[0] = 0;
    int ct = 0, chan = 0, le= 0;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
    }
    if(arr[1]==1) {
        cout<<"YES\n";
        return;
    }
    for(int i=2;i<=n;i++){
        if(arr[i]%arr[1]!=0){
            ct=1; break;
        }
    }
    if(ct==1) cout<<"NO\n";
    else cout<<"YES\n";
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