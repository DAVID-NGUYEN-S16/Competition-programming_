#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IMPORTANT 1
#define UNIMPORTANT 0

const ll MAX = 1e6+ 7;
const ll INF  = 1e9 + 7;
void solve()
{
    int n, k, d; cin>>n>>k>>d;
    vector<pair<int, int>> eg[n+5];
    vector<bool> visited(n+5);
    vector<int> color(n+5, UNIMPORTANT);
    queue<int> q;
    for(int i = 1; i <= k ; i++)
    {
        int ps; cin>>ps;
        q.push(ps);
        visited[ps] = true;
    }
    for(int i = 1; i < n; i++)
    {
        int u, v; cin>>u>>v;
        eg[u].push_back({v, i});
        eg[v].push_back({u, i});
    }
    while(!q.empty())
    {
        int ps = q.front();
        q.pop();
        for(auto x: eg[ps]){
            if(!visited[x.first]){
//                    cout<<ps<<" "<<x.first<<" "<<x.second<<endl;
                color[x.second] = IMPORTANT;
                visited[x.first] = true;
                q.push(x.first);
            }
        }
    }
    vector<int>ans;
    for(int i = 1; i < n; i++){
        if(color[i] == UNIMPORTANT) ans.push_back(i);
    }
    cout<<ans.size()<<"\n";
    for(auto x: ans) cout<<x<<" ";
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
