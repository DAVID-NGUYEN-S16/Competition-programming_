#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e18+7;
const ll INF=1e18+7;
const ll MIN=- 1e5+7;
const ll MAX= 1e5+1;    
long long isPrime[MAX];
vector<long long> prime;
void eratosthenes(){
    for(long long i = 2; i<MAX; i++){
        if(isPrime[i] == 0 ){
            for(long long j = i*i; j<MAX; j+=i){
                isPrime[j] = i;
            }
        }
    }
    for(int i = 2; i<MAX; i++) if(!isPrime[i]) {
        isPrime[i] = i;
        prime.push_back(i);
    }
}
long long pw(int a, int b){
    long long res = 1;
    for(long long i = 1; i<=b; i++){
        if(INF/res < a) {
            // c
            return 0;
        }
        res*=a;
        // cout<<INF/res<<" "<<a<<" "<<res<<"\n";
    }
    return res;
}
void solve()
{
    eratosthenes();
    long long n, ans = 1; cin>>n;
    if(isPrime[n] == n || n%2 !=0){
        ans = pw(2, n-1);
        if(ans == 0) cout<<-1;
        else cout<<ans;
    }else{
        for(int i = 0; i<n/2; i++) {
            if(INF/ans <prime[i]) {
                cout<<"-1"; return;
            }
            ans*=prime[i];
            // cout<<ans<<"\n";
            // return;
        }
        cout<<ans;
    }

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    freopen("cntdiv.inp", "r", stdin);
    freopen("cntdiv.out", "w", stdout);
    // #endif
    // ll tc=1; cin>>tc;
    // for (ll t=1; t<=tc; t++) 
    solve();
    return 0;
}
