/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e9+7;
const ll INF=1e18+7;
const ll MIN=- 1e5+7;
ll comput(ll n, ll i, ll j){
    if(n>i && n>j) return 0;
    return max(i,j)-n+1;
}
void solve()
{
    ll n; cin>>n;
    vector<ll>arr(n+5), dp(n+5);
    for(ll i=1;i<=n;i++) cin>>arr[i];
    ll ans = INF;
    if(n%2!=0){
        ans = 0;
        for(ll i=2;i<n;i+=2){
            ans+=comput(arr[i], arr[i-1], arr[i+1]);
        }
        cout<<ans<<"\n"; return;
    }
    vector<ll>pref(n+5), suff(n+5), buid(n+5);
    for(ll i=2;i<n;i++){
        buid[i] = comput(arr[i], arr[i-1], arr[i+1]);
    }
    pref[2] = buid[2];
    suff[n-1] = buid[n-1];
    for(ll i=2;i<n;i++){
        pref[i] = pref[i-2] + buid[i];
    }
    for(ll i=n-2;i>2;i--){
        suff[i] = suff[i+2] + buid[i];
    }
    for(ll i=2;i<=n-2;i+=2){
        ans = min(ans, pref[i] + suff[i+3] );
    }
    // Tai sao lại cộng 3 mà không phải cộng 2. 
    // nhìn vào suff ta tính từ 
    // vd 1 2 3 4 5 6 7 8  thì suff sẽ nhận các số 7 5 3 
    // còn pref 2 4 6 nhận thi thấy nếu 2 đi với 3 thì ko được ta cần phải nhích lên 5 vì thế + 3.
    cout<<min(min(pref[n-2], suff[3]),ans)<<"\n";
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