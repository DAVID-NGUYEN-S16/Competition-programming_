/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define  c cout<<"yes"<<endl;
const ll INF=1e5+7;
const ll MIN=- 1e5+7;
void solve()
{
    ll n, m; cin>>n>>m;
    ll  a[m+5];
    map<int,int>mp;
    for(int i=1;i<=m;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    int v[n+5];
    for(int i=1;i<=n;i++){
        v[i] = mp[i];
    }
    sort(v+1,v+n+1,greater<int>());
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(v[j]+2<=v[i]-1) {
                v[i]-=1;
                v[j]+=2;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(v[j]+2<=v[i]-1) {
                v[i]-=1;
                v[j]+=2;
            }
        }
    }
    // int j = n;
    // for(int i=1;i<=n;i++){
    //     if(v[j]+2<=v[i]) {
    //             v[i]-=1;
    //             v[j]+=2;
    //     }
    //     j--;
    //     if(j==0) break;
    // }
    // for
    sort(v+1,v+n+1);
    // for(int i=1;i<=n;i++) cout<<v
    cout<<v[n]<<"\n";
  
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