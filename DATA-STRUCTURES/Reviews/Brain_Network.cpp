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
int n,m;
vector<int>v[INF];
int parent[INF];
bool check[INF];
int ans = 0, child=0;
void dfs(int i, int par){
    parent[i] = parent[par]+1;
    check[i] = true;
    for(auto x: v[i]){
        if(check[x]==false){
            dfs(x, i);
        }
    }
    if(parent[i]>ans) {
        child = i;
    }
    ans = max(ans, parent[i]);
}
void solve()
{
    cin>>n>>m;
    int x, y;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 0);
    memset(check, false, sizeof(check));
    dfs(child, 0);
    cout<<ans-1<<"\n";
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