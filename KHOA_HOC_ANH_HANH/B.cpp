#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e9+7;
const ll INF=10001001;
const ll MIN=- 1e5+7;
bool notPrime[INF];
bool check(ll x){
    string s = to_string(x);
    ll i = 0, j = s.size()-1;
    while(i<j){
        if(s[i] != s[j]) {
            // cout<<i<<" "<<j<<"\n";
            return  false;
        }
        i++; j--;
    }
    return true;

}
void solve()
{
    for(ll i = 2; i*i<=1000; i++){
        if(!notPrime[i]){
            for(ll j  = i*i; j<=INF; j+=i){
                notPrime[j] = true;
            }
        }
    }
    ll l, r; cin>>l>>r;
    ll sum = 0;
    notPrime[1] = true;
    for(ll i = l; i<=r; i++){
        if(i<=INF && notPrime[i] == false && check(i) == true){
            sum+=i;
        }
    }
    cout<<sum;

}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    freopen("palinprime.inp", "r", stdin);
    freopen("palinprime.out", "w", stdout);
    // #endif
    //ll tc=1; cin>>tc;
    //for (ll t=1; t<=tc; t++) 
    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e9+7;
const ll INF=1e5+7;
const ll MIN=- 1e5+7;
void solve()
{
    
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