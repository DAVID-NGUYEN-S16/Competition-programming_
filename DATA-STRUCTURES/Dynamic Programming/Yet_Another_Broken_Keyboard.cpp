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
    ll n, k; cin>>n>>k;
    string s; cin>>s;
    vector<ll>dp(n+5);
    map<char, ll>cnt;
    char cs;
    for(ll i=1;i<=k;i++){        
        cin>>cs; 
        cnt[cs]=1;
    }
    dp[0] = cnt[s[0]];
    if(cnt[s[0]]==1 && cnt[s[1]]==1) dp[1] = 3;
    else dp[1] = 1*max(cnt[s[1]],cnt[s[0]]);
    for(ll i=2;i<s.size();i++){
        dp[i] = max(dp[i-1], 2*(dp[i-1]-dp[i-2])*cnt[s[i]] + cnt[s[i]]+dp[i-2]);
        // cout<<dp[i]<<" ";
    }
    cout<<dp[n-1]<<"\n";
    
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