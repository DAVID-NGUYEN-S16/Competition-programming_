#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e18+7;
const ll INF=1e6+1;
ll cntPrime[INF];
ll pow(ll a, ll x, ll stop){
    ll ans = 1;
    for(ll i = 1; i<=x; i++) {
        if(ans > stop/a) return stop+1;
        ans*=a;
    }
    return ans;
}
ll bs(ll x, ll n){
    ll l = 1, r = sqrt(n);
    while(l<=r){
        
        ll mid = (l+r)/2;
        ll res= pow(mid, x, n) ;
        if(res== n) return mid;
        if(res>n) r = mid -1;
        else l = mid +1;
    }
    return -1;
}
ll phantich(ll n){
    ll dem =1;
    if(n<=1e6) return cntPrime[n];
    else {
        int  cnt = 0;
        for(int i = sqrt(n);i>=2; i--){
            while(n%i==0) {
                n/=i; 
                cnt++;
                if(n%i==0 && n/2 <=INF) return cntPrime[i] + cnt;
            }
        }
    }
    
}
bool check_prime(ll n){
    for(int i = 2; i<=sqrt(n); i++){
        if(n%i==0) return false;
    }
    return true;
}
void dem_uoc(){
    for(int i = 1; i<=INF; i++){
        for(int j = i; j<=INF; j+=i){
            cntPrime[j]++;
        }
    }
}
void solve()
{
    ll n ; cin>>n;
    if(n==1){
        cout<<1<<" ";
        return;
    }

    ll x = sqrt(n);
    if(x*x == n && check_prime(x)){
        cout<<x<<" ";
    }else{
        for(int souoc = 64; souoc>=2; souoc--){
            ll ans = bs(souoc, n);
            if(ans == -1) continue;
            if(souoc == phantich(ans)) {
                cout<<ans<<" ";
                return;
            }
            
        }
        cout<<"-1 ";
    }
    // cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // freopen("divpow.inp", "r", stdin);
    // freopen("divpow.out", "w", stdout);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    dem_uoc();
    int t; cin>>t;
    
    while(t--)
    solve();
    return 0;
}