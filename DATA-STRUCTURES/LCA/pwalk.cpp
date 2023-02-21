// https://oj.vnoi.info/problem/pwalk
#include<bits/stdc++.h>
using namespace std;
const long long MAX = 1e5+7;
const long long INF = 1e18 + 7;
#define next first
#define cost second
vector<pair<int, int>> v[MAX];
long long sum[MAX], depth[MAX], up[1001][1001] ;
bool check[MAX];
void dfs(int a){
    //cout<<"yes "<<a <<endl;
    check[a] = true;
    for(auto b: v[a]){
        if(check[b.first] == false) {
            depth[b.next] = depth[a] + 1;
            sum[b.next] = sum[a] + b.cost;
            up[b.next][0] = a;
            for(int i  =1; i<14; i++){
                up[b.first][i] = up[up[b.first][i-1]][i-1];
            }
            dfs(b.first);
        }
        
    }
}
long long lca(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);
    // balence
    int k = depth[a] - depth[b];
    for(int i = 13; i>=0 ; i--){
        if(k&(1<<i)) a = up[a][i];
    }
    if(a == b) return a;
    // move two poin up 2^i

    for(int i = 13; i>=0; i--){
        if(up[a][i] != up[b][i]){
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}
void solve()
{
    int n,q; cin>>n>>q;
    int a, b, c; 
    for(int  i = 0; i<n-1 ; i++){
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    dfs(1);
    for(int i = 1; i<=q; i++){
        cin>>a>>b;
        int par_common = lca(a, b);
        cout<<abs(sum[a] + sum[b] - 2*sum[par_common])<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}