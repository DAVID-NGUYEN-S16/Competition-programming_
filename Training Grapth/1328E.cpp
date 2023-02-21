#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 1e6 + 7;
const ll INF = 1e9 + 7;
int par[MAX], tin[MAX], tout[MAX], depth[MAX];
bool visited[MAX];
int times = 0;
vector<int> eg[MAX];
void dfs(int id, int ps, int d)
{

    par[id] = ps;
    tin[id] = times++;
    depth[id] = d;
    visited[id] = true;
    for(auto x: eg[id]){
        if(!visited[x])
            dfs(x, id, d + 1);
    }
    tout[id] = times++;
//    cout<<id<<" : "<< tin[id]<<" "<<tout[id]<<endl;
}
bool isancestor(int u, int vmax){
    return tin[u] < tin[vmax] && tout[u] > tout[vmax];
}
void solve()
{
    int n, m; cin>>n>>m;
    int u, v;
    for(int i = 1; i < n; i++)
    {
        cin>>u>>v;
        eg[u].push_back(v);
        eg[v].push_back(u);
    }
    dfs(1, -1, 0);
    while(m--)
    {
        int k; cin>>k;
        vector<int> arr(k);
        for(int &x: arr) cin>>x;
        // find max depth of segment
        int max_depth = 1;
        for(int x: arr) if(depth[x] > depth[max_depth]) max_depth = x;
        int flag = 0;
        // check ancestor of all vertor
        for(int x: arr){
            if(x == max_depth ||   x == 1) continue;
            if(!isancestor(x, max_depth)){
                if(!isancestor(par[x], max_depth)){
                    flag = 1;
                }
            }
        }
        if(flag == 0) cout<<"YES\n";
        else cout<<"NO\n";

    }

}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
