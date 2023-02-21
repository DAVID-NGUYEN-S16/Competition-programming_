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
ll bit[20][INF], arr[INF], cnt[INF], n;
void update(ll i, ll v, ll sz){
    for(;i<=n;i+=i&-i) bit[sz][i]+=v;
}
ll gevl(ll i, ll sz){
    ll sum = 0;
    for(;i>0;i-=i&-i) sum+=bit[sz][i];
    return sum;
}
void solve()
{
    ll k; cin>>n>>k;
    k++;
    for(ll i=1;i<=n;i++) {
        cin>>arr[i];
        // cout<<arr[i]<<""
        cnt[i]=1;
    }
    for(ll i=2;i<=k;i++){
        for(ll j=1;j<=n;j++){
            update(arr[j]+1, cnt[j], i);
            cnt[j] = gevl(arr[j],i);
            // cout<<cnt[i]<<" ";
        }
        // cout<<"\n";
    }
    ll ans = 0;
    for(ll i=1;i<=n;i++) ans+=cnt[i];
    cout<<ans<<"\n";
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