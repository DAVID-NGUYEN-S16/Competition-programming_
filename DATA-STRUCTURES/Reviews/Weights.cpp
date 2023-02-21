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
    vector<int>arr(n+5), dis(n+5), weght(n+5);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        cin>>dis[i];
        weght[dis[i]] = i;
    }
    bool ch = 1;
    for(int i=1;i<=n;i++){
        if(weght[arr[i]]>weght[i]) {
            ch=0; break;
        }
    }
    if(ch==1){
        for(int i=1;i<=n;i++){
            cout<<weght[i]- weght[arr[i]]<<" ";
        }
    }else cout<<-1;
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