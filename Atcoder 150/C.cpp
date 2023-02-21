#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 1e6 + 7;
string s[MAX];
vector<int> v[MAX], ans[MAX];
queue<int> tap;
bool check[MAX] ;
void dfs(int i){
    cout<<i<<endl;
    if(v[i].size() == 0 && ans[i].size()!=0){
        ans[i].push_back(tap.front());
        tap.pop();
        return;
    }
    check[i] = true;
    for(auto x: v[i]){
        if(!check[x]){
            dfs(x);
        }
    }
    for(auto x: v[i]){
        for(auto p: ans[x]) {
                ans[i].push_back(p);
        }
    }
}
void solve()
{
    int n; cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin>>s[i][j];
            if(s[i][j] == '1') v[j].push_back(i);
        }
        tap.push(i);
    }
    for(int i = 1; i <= n; i++){
        if(check[i] == false) dfs(i);
    }
    for(int i = 1; i <= n; i++){
        cout<<ans[i].size()<<" ";
        for(auto x: ans[i]) cout<<x<<" ";
        cout<<"\n";
    }


}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    //    #ifndef ONLINE_JUDGE
//   freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    #endif
//    int t; cin>>t;
//    while(t--)
    solve();
}

