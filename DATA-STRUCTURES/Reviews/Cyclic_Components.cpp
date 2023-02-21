/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e9+7;
const ll INF=2e5+7;
const ll MIN=- 1e5+7;
int n, m; 
vector<int>v[INF];
bool check[INF];
int par[INF];
int dfs(int i,int cur){
    if(v[i].size()!=2) {
        par[cur]=1;
    }
    check[i] = true;
    for(auto x: v[i]){
        if(!check[x]) {
            dfs(x, cur);
        }
    }
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
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(!check[i]){
            dfs(i, i);
            if(par[i]==0) cnt++;
        }
    }
    cout<<cnt;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
solve();
    return 0;
}