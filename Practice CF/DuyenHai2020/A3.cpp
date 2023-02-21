#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl; 
const ll MOD=1e9+7;
const ll INF=1e5+7;
const ll MIN=- 1e5+7;
// string 
string encode(string s){
    string ans = "";
    char cs = s[0];
    ll j = 0;
    while(j<s.size()){
        if(s[j] >='0' && s[j] <= '9'){
         //   c
            ll cnt = 0;
            while(s[j] >='0' && s[j] <= '9'){
                cnt = cnt*10 + (s[j] - '0');
                j++;
            }
            j--;
            while (cnt--)
            {
                ans.push_back(cs);
            } 
            
        }else {
            cs = s[j];
           
        }
        j++;
    }
    return ans;
}
void solve()
{
    ll n, m; cin>>n>>m;
    string t, p; cin>>t>>p;
    t = encode(t);
    // cout<<t<<endl;
    ll cnt = 0;          
    for(ll i = 0; i < (1<<n); i++){
        string ans ="";
        for(ll j = 0; j < n; j++ ){
            if(i&(1<<j)) ans.push_back(t[j]);
        }
        if(ans == p) cnt++;
    }
    cout<<cnt;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    freopen("PASSWORD.INP", "r", stdin);
    freopen("PASSWORD.OUT", "w", stdout);
    // #endif
    //ll tc=1; cin>>tc;
    //for (ll t=1; t<=tc; t++) 
    solve();
    return 0;
}