// https://www.spoj.com/problems/LCASQ/
#include<bits/stdc++.h>
using namespace std;
const long long MAX = 10000;
const long long LOG = 14;
vector<int> children[MAX];
int up[MAX][LOG]; //  up[v][j] is 2^j-th ancestor of v
int depth[MAX]; 
void dfs(int a){
    for(int b: children[a]){
        depth[b] = depth[a] + 1;
        up[b][0] = a; // a is parent of b
        for(int i = 1; i < LOG; i++) up[b][i] = up[up[b][i-1]][i-1];
        dfs(b);
    }
}
int get_lca(int a, int b)
{
    if(depth[a] < depth[b]) swap(a, b);
    // balence depth
    int k = depth[a] - depth[b];
    for(int i = LOG-1; i >= 0; i --){
        if(k & (1<<i)) a = up[a][i];
    }
    // if b was ancestor of a then now a == b
    if(a == b){
        return a;

    }
    // move both a and b with 2^i
    for(int i = LOG - 1; i >=0; i--){
        if(up[a][i] != up[b][i]){
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}
void solve()
{
    int n; cin>>n;
    int x, p;
    for(int  i = 0; i<n; i++){
        cin>>x;
        for(int j = 0; j<x; j++){
            cin>>p;
            children[i].push_back(p);
        }
    }
    dfs(0);
    int q; cin>>q;
    int chil1, chil2; 
    while(q--)
    {
        cin>>chil1>>chil2;
        cout<<get_lca(chil1, chil2)<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}