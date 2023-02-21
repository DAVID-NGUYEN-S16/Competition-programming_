#include<bits/stdc++.h>
using namespace std;
const long long MAX = 1e5+7;
const long long LOG= 14;
long long matrix[2001][2001], depth[MAX], up[MAX][18], sum[MAX];
bool check[MAX];
long long n;

struct node
{
    long long chil, par, vl;
    node(long long a, long long b, long long c){
        chil  = a;
        par   = b;
        vl    = c;
    }
    bool operator <(const node &t)const{
        return vl>t.vl;
    }
};
vector<long long>v[MAX];
void dfs(long long a){
   //cout<<a<<endl;
    for(auto b: v[a]){
        depth[b] = depth[a] + 1;
        sum[b] =sum[a] + matrix[a][b];
        up[b][0] = a;
        for(long long i = 1; i< LOG; i++){
            up[b][i] = up[up[b][i-1]][i-1];
        }
        dfs(b);
    }
}
long long lca(long long a, long long b)
{
    if(depth[a] < depth[b]) swap(a, b);
    // balance
    long long k = depth[a]  - depth[b];
    for(long long i = LOG-1; i>=0; i--){
        if(k&(1<<i)) a = up[a][i];
    }
    if(a == b) return a;
    for(long long i = LOG-1; i >= 0; i--){
        if(up[a][i] != up[b][i]){
            a = up[a][i];
            b = up[b][i];
        }
    }
    // cout<<a<<" -- \n";
    return up[a][0];
}
priority_queue<node>p;
void solve()
{
    cin>>n;
    for(long long i = 1; i<=n; i++){
        for(long long j = 1; j<=n; j++){
            cin>>matrix[i][j];
        }
    }
    // check 1
    for(long long i = 1; i<=n; i++){
        for(long long j = 1; j<=n; j++){
            if(matrix[i][j] != matrix[j][i]  ||(matrix[i][j]==0&&i!=j)){
                cout<<"NO\n";
                return;
            }
        }
    }
    // quy ve tree
    
    p.push(node(1, 0, 0));
    map<long long, long long> mp;
    while(!p.empty())
    {
        long long u = p.top().chil, pa = p.top().par;
        p.pop();
        if(check[u] == true) continue;
        mp[pa] = 0;
        v[pa].push_back(u);
        check[u] = true;
        for(long long i = 1; i<=n ; i++){
            if(check[i] == false){
                p.push(node(i, u, matrix[u][i]));
            }
        }
    }

    dfs(1);

    for(long long i = 1; i<=n; i++){
        for(long long  j = 1 ; j <=n; j++){
            long long par = lca(i, j);
            long long dist = sum[i] + sum[j] - 2*sum[par];
            if(dist != matrix[i][j]){
                cout<<"NO\n";
                return ;
            }
        }
    }
    cout<<"YES\n";
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}