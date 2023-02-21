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
int n, color[INF];
map<int,vector<int>>v;
map<int,bool> check;
bool BFS(int i){
    queue<int>p;
    color[i] = 1;
    check[i] = true;
    p.push(i);
    while(!p.empty()){
        int x = p .front();
        p.pop();
        for(auto k: v[x]){
            if(check[k]){
                if(color[k]==1 - color[x]) continue;
                return true;
            }
            if(!check[k]){
                color[k] = 1 - color[x];
                p.push(k);
                check[k] = true;
            }
        }
    }
    return false;
}
void solve()
{
    cin>>n;
    int x, y, ct= 1;
    check.clear();
    memset(color, 0, sizeof(color));
    v.clear();
    map<int,int>cnt;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        cnt[x]++;
        cnt[y]++;
        if(cnt[x]>=3 || cnt[y]>=3) ct = 0;
    }
    for(int i=1;i<=n;i++){
        if(!check[i]|| ct==0){
            if(BFS(i)||ct == 0) {
                cout<<"NO\n"; return ;
            }
        }
    }
    cout<<"YES\n";
   
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) 
solve();
    return 0;
}