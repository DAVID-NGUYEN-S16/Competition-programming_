/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e15+7;
const ll INF=1e5+7;
const ll MIN=- 1e5+7;
ll n, ans = MOD;
vector<pair<ll,ll>> v[505];    
ll dp[INF][505], cnt[INF][505];
bool check[505][505];
ll ch[505][505];
ll cl = 0, idnew = 1, dem = 0;
ll chan = 2;
void dfs(ll i, ll par, ll vl){
    dp[idnew][i] = dp[idnew][par] + vl;
    cnt[idnew][i] = cnt[idnew][par] + 1;
    check[idnew][i] = true;
    if(cnt[idnew][i]==n){
        ans = min(ans,dp[idnew][i]);
    }
    if(i%2==0){
        chan +=2;
        for(auto x: v[i]){
            if(check[idnew][i]==false){
                dfs(x.first, i, x.second);
            }
        }
    }else{
        dfs(chan, i, v[i][chan].second);
    }
} 
void solve()
{

    cin>>n; 
    ll x, y;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            cin>>x;
            if(ch[i][j]==0 && ch[j][i]==0){
                v[i].push_back({j, x});
                v[j].push_back({i,x});
                ch[i][j]=1;
            }
        }
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