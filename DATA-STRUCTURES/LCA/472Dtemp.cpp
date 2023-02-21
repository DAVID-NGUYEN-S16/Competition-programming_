#define bug(x) cout<<#x<<" is "<<x<<endl;
#define IO std::ios::sync_with_stdio(0);
#include <bits/stdc++.h>
#define iter ::iterator
using namespace  std;
typedef long long ll;
typedef pair<ll,ll>P;
typedef pair<P,P>P1;
#define mk make_pair
#define pb push_back
#define se second
#define fi first
#define rs o<<1|1
#define ls o<<1
const int N=2e3+5;
ll mod=1e9+7;
int n;
ll a[N][N];
vector<int>g[N];
int st[N][30];
int d[N],lg[N];
ll sum[N];
struct node{
    int u,fa,w;
    node(int a,int b,int c){
        u=a,fa=b,w=c;
    }
    bool operator <(const node &t)const{
        return w>t.w;
    }
};
void dfs(int u,int fa){
    d[u]=d[fa]+1;
    sum[u] = sum[fa] + a[fa][u];
    st[u][0]=fa;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==fa)continue;
        dfs(v,u);
    }
}
void init(){
    for(int i=1;i<=n;i++){
        lg[i]=lg[i-1]+((1<<lg[i-1])==i);
    }
    for(int i=1;i<=20;i++){
        for(int j=1;j<=n;j++){
            st[j][i]=st[st[j][i-1]][i-1];
        }
    }
}
int lca(int x,int y){
    if(d[x]<d[y])swap(x,y);
    while(d[x]>d[y]){
        int h=lg[d[x]-d[y]]-1;
        x=st[x][h];
    }
    if(x==y)return x;
    for(int i=lg[d[x]]-1;i>=0;i--){
        if(st[x][i]!=st[y][i]){
            x=st[x][i];
            y=st[y][i];
        }
    }
    return st[x][0];
}
priority_queue<node>q;
int vis[N];
int main(){
    IO;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]!=a[j][i]||(a[i][j]==0&&i!=j)){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    q.push(node(1,0,0));
    map<int, int> mp;
    while(!q.empty()){
        int u=q.top().u;
        int fa=q.top().fa;
        q.pop();
        if(vis[u])continue;
        g[fa].pb(u);
        mp[fa] = 0;
        vis[u]=1;
        for(int i=1;i<=n;i++){
            if(!vis[i])q.push(node(i,u,a[u][i]));
        }
    }
    for(auto x: mp){
        for(auto y: g[x.first]){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    dfs(1,0);
    init();
    // cout<<"++"<<lca(1,2)<<" "<<a[1][2];
    // cout<<"\n"<<sum[1]<<" "<<sum[2]<<" "<<sum[lca(1,2)];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x=lca(i,j);
            ll h=sum[i]+sum[j]-2*sum[x];
            if(h!=a[i][j]){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
}