/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define  c cout<<"yes"<<endl
const ll MOD=1e9+7;
const ll INF=1e5+7;
const ll MIN=- 1e5+7;
string s[INF];
int n, m; 
int move1[] = {1,-1, 0, 0};
int move2[] = {0,0, 1, -1};
map<char, int> cnt;
map<pair<int,int>, bool> check, cur;
bool inside(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}
bool predict(int x, int y, char sc){
    if(inside(x+1, y) && s[x+1][y]==sc && cur[{x+1, y}]==false && check[{x+1, y}]== true) return true;
    if(inside(x-1,y) && s[x-1][y]==sc && cur[{x-1,y}]== false && check[{x-1,y}]== true) return true;
    if(inside(x,y-1) && s[x][y-1]==sc && cur[{x,y-1}]== false && check[{x,y-1}]== true) return true;
    if(inside(x,y+1) && s[x][y+1]==sc&& cur[{x,y+1}]== false && check[{x,y+1}]== true) return true;
    return false;
}
bool BFS(int x, int y, char sc){
    queue<pair<int,int>>p;
    p.push({x,y});
    check[{x, y}] = true;
    // cout<<111;
    cnt[sc]++;
    while(!p.empty()){
        int c  = p.front().first, d = p.front().second;
        p.pop();
        cur[{c, d}] = true;
        // cout<<1<<"\n";
        for(int i=0;i<4;i++){
            int k = c+move1[i], h= d+move2[i];
            if(check[{k, h}]|| !inside(k, h)||s[k][h]!=sc) continue;
            // cout<<k<<" "<<h<<" "<<c<<" "<<d<<" "<< cnt[sc]<<"\n";
            if(predict(k, h, sc) && cnt[sc]>=3) return true;
            if(!check[{k,h}]){
                check[{k,h}]=true;
                p.push({k,h});
                cnt[sc]++;
            }
        }
        cur[{c, d}] = false;
    }
    return false;

}

void solve()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    // cout<<111;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!check[{i,j}]){
                if(BFS(i, j, s[i][j])){
                    cout<<"Yes"; return ;
                }
            }
        }
    }
    cout<<"No";
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