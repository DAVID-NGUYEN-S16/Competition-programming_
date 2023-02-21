#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 1e6 + 7;
const ll INF = 1e9 + 7;
vector<int> v[MAX];
ll n, m, x, y;
map<int, int> mp[MAX];
void solve()
{
     cin>>n>>m>>x>>y;
    int u, vs, w;
    for(int i = 1; i <= m; i++){
        cin>>u>>vs>>w;
        mp[u][vs] = max(mp[u][vs], w);
        mp[vs][u] = max(mp[vs][u], w);
        v[u].push_back(vs);
        v[vs].push_back({u});

    }
    queue<pair<int, int>>p;

    p.push({x, INF});
    vector<ll> ans(400, -1);
    while(!p.empty()){

        u = p.front().first, w = p.front().second;
//        cout<<u<<" + "<<w<<endl;
        p.pop();
        for(auto x: v[u]){
            if(ans[x] < min(mp[u][x], w)){
                ans[x] = min(mp[u][x], w);
//                cout<<ans[x]<<endl;
                p.push({x, ans[x]});
            }
        }
    }
    cout<<ans[y];


}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}


//#include<bits/stdc++.h>

//using namespace std;
//#define ll long long
//const ll MAX = 1e6 + 7;
//const ll INF = 1e9 + 7;
//vector<int> v[MAX];
//int check[MAX];
//ll n, m, x, y;
//ll dp[MAX];
//ll ans = 0;
//map<int, int> mp[MAX];
//ll dfs(ll id, ll par, ll ws)
//{
//
//    dp[id] = min(ws, dp[par]);
//    if(id == y){
//        return  dp[id];
//    }
//    check[id] = 1;
//    ll ans = dp[id];
//    for(auto p: v[id]){
//        if(check[p] == 0){
//                cout<<id<<" "<<p<<endl;
//            ans = min(ans, dfs(p, id, mp[id][p] ));
//            check[p] = 0;
//        }
//    }
//    check[id] = 0;
//    ans = min(dp[id], ans);
////    cout<<id<<" "<<ans<<" "<<check[4]<<endl;
//    return ans;
//}
//void solve()
//{
//
//     cin>>n>>m>>x>>y;
//    int u, vs, w;
//    for(int i = 1; i <= m; i++){
//        cin>>u>>vs>>w;
//        mp[u][vs] = max(mp[u][vs], w);
//        mp[vs][u] = max(mp[vs][u], w);
//        v[u].push_back(vs);
//        v[vs].push_back({u});
//
//    }
//    dp[0] = INF;
//    cout<<dfs(x, 0, INF);
////    if(ans == 0) {
////        cout<<-1; return;
////    }
////    cout<<ans;
//
//
//}
//int main()
//{
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
//    cout.tie(NULL);
//    solve();
//    return 0;
//}
