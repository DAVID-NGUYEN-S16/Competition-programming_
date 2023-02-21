#include<bits/stdc++.h>
using namespace std;
int const N=1e6+10;int n,m,ttx,tty,res;
vector<int>vis[N];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
string s[N];
inline void dfs(int x,int y,int dep){
    vis[x][y]=dep;
    cout<<x<<" "<<y<<endl;
    for (int i=0;i<4;++i){
        int tx=x+dx[i];
        int ty=y+dy[i];
        if (tx<1 || ty<1 || tx>n || ty>m || s[tx][ty]=='#') continue;
        if (tx==ttx && ty==tty && abs(vis[tx][ty]-vis[x][y])+1>=4) {
                cout<<tx<<" + "<<ty<<endl;
                res=1;
        }
        if (vis[tx][ty]) continue;
        dfs(tx,ty,dep+1);
    }
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        cin>>s[i],s[i]=" "+s[i];
        vis[i].push_back(0);
        for (int j=1;j<=m;++j) vis[i].push_back(0);
    }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            if (s[i][j]=='S'){
                ttx=i,tty=j;
                break;
            }
    dfs(ttx,tty,1);
    if (res) cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}

