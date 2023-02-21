#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e9+7;
const ll INF=1e6+1;
const ll MIN=- 1e5+7;
ll prime[INF], arr[INF], n, cnt[INF];
void sannguyeto(){
    // vì dưới 10^5 chỉ có 1001 số nguyên tố
    for(ll i=2;i<=1001;i++){
        if(!prime[i]){
            prime[i] = i;
            for(ll j = i*i;j<=INF;j+=i){
                if(!prime[j]) prime[j] = i ;
            }
        }
    }
    for(ll i=1001;i<=INF;i++) if(!prime[i]) prime[i] = i;
}

void solve()
{
    ll n; cin>>n;
    sannguyeto();
    // phân tách mẫu n VS k
    // for(int i=1; i<=n;i++){
    //     int res = i;
    //     while(res>1){
    //         cnt[prime[res]]++;
    //         res/=prime[res];
    //     }
    // }
    ll m = n;
    
    for(int i = 1; i<=m; i++){
        cout<<i<<" "<<cnt[i]<<"\n";
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