#include<bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 7;
const long long LOG = 18;
vector<int>group[MAX];
vector<int> v[MAX];
int depth[MAX], up[MAX][18];
bool check[MAX];
// xay dung lca
void dfs(int a){
    check[a] = 1;
    for(auto b: v[a]){
        if(check[b] == false) {
            depth[b] = depth[a] + 1;
            up[b][0] = a;
            for(int i = 1; i < LOG; i++) up[b][i] = up[up[b][i-1]][i-1];
            dfs(b);
        }
        
    }

}
int lca(int a, int b)
{
    if(depth[a] < depth[b]) swap(a,b);
    // balance
    int k = depth[a] - depth[b];
    for(int i = LOG -1; i >=0; i--){
        if(k&(1<<i)) a = up[a][i];
    }
    if(a == b) return a;
    for(int i = LOG -1; i >=0; i--){
        if(up[a][i] != up[b][i]){
            b = up[b][i]; a = up[a][i] ;
        }
    }
    return up[a][0];
}
// tim diem xa nhat
int far_most(int i){
    int a = group[i][0], mas = 0, b = 0;
    for(auto x: group[i]){
        int par = lca(a, x);
        int dist = depth[a]+ depth[x] - 2*depth[par];
        // cout<<a<<" "<<x<<" far: "<<par<<endl;
        // cout<<depth[a]<<" "<< depth[x] <<" "<<depth[par]<<" "<<dist<<endl;
        if(dist >= mas){
            b = x;
            mas =dist;
        }
    }
    // cout<<"FAR: "<<b<<endl;
    mas = 0 ;
    for(auto x: group[i]){
        int par = lca(b, x);
        int dist = depth[b]+ depth[x] - 2*depth[par];
        if(dist >= mas){
            
            mas = dist;
        }
    }
    return mas;
}
void solve()
{
    int n, k; cin>>n>>k;
    int x, y, root;
    for(int i = 1; i<=n; i++){
        cin>>x>>y;
        v[y].push_back(i);
        v[i].push_back(y);
        group[x].push_back(i);
        if(y == 0) root = i;
    }
    // for(auto x: group[1]) cout<<x<<" ";
    // cout<<root<<endl;
    dfs(root);
    // cout<<depth[6]<<endl;
    for(int i = 1; i <= k; i++){
        cout<<far_most(i)<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}