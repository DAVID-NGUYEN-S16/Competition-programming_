#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e9+7;
const ll INF=1e5+7;
const ll MIN=- 1e5+7;
void solve()
{
    int n, k; cin>>n>>k;
    string re , ans;
    cin>>re>>ans;
    vector<int> have(27), need(27);
    for(auto x: re) have[x- 'a'] ++;
    for(auto x: ans) need[x- 'a'] ++;
    int  cnt = 0;
    bool bad = false;
    for(int i = 0; i <26; i++){
        if(have[i] < need[i] || (have[i] -= need[i])%k)  bad = true;
        have[i+1] += have[i];
    }
    if( !bad ) cout<<"Yes\n";
    else cout<<"No\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) 
    solve();
    return 0;
}