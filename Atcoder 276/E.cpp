#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long MAX = 1e6 + 7;
const long long INF = 1e18 + 7;
const long long MOD = 1e9 + 7;
string s[MAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
map<long long, int> vis[MAX];
int h, w;
bool inside(int x, int y){
    return x >0 && x <= h && y >0 && y <= w;
}
int curx , cury;
bool ch = false;
void dfs(int x, int y,int cnt){
    vis[x][y] = cnt;
//    cout<<x<<" "<<y<<" "<<vis[x][y]<<endl;
    for(int i = 0; i < 4; i++){
        int u = dx[i] + x, v = dy[i] + y;
        if(!inside(u, v) || s[u][v] == '#') continue;
        if(u == curx && v == cury && abs(vis[x][y] - vis[u][v]) + 1 >= 4) {
//                cout<<u<<" "<<v<<" "<<x<<" "<<y<<endl;
                ch = true;

        }
//        if(u == curx && v == cury){
//                cout<<"\n+++\n";
//                cout<<u<<" "<<v<<" "<<x<<" "<<y<<endl;
//                cout<<vis[u][v]<<" "<<vis[x][y]
//                cout<<"\n+++\n";
//        }
        if(vis[u][v]) continue;

        dfs(u, v, cnt+1 ) ;
    }
}
void solve()
{
    cin>>h>>w;
    for(int i = 1; i <= h; i++){
        cin>>s[i];
        s[i] = "+"+ s[i];
    }
    int x = 0, y = 0;
    for(int i = 1; i <= h; i++ ){
        for(int j = 1; j <= w; j++){
            if(s[i][j] == 'S') x = i, y = j;
        }
    }
    curx = x;
    cury = y;
    dfs(x, y, 1);
    if(ch) cout<<"Yes";
    else cout<<"No";
}
int main()
{

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

