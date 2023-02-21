#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MAX = 2e5 + 7;
const long long MIN =  -1e6;
const long long MOD = 1e9 + 7;
const long long INF = 1e18 + 7;
const long long base = 31;
vector<int>v[MAX];
bool check[MAX];
int color[MAX];
bool dfs(int id , int last){
    color[id] = last;
    check[id] = true;
//    cout<<id<<" Color: "<<color[id]<<endl;
    for(auto x: v[id]){
        if(check[x]){
            if(color[id] == color[x]) {
                    //cout<<id<<" - "<<x<<endl;
                    return false;
            }
        }else {
//            cout<<id<<" + "<<x<<endl;
            if(check[x] == false && dfs(x, 1 - last) == false) {
//                    cout<<"aaa";
                    return false;
            }

        }
    }
    return true;
}
void clears(){
    for(int i = 1; i<=MAX; i++) {
        check[i] = false;
        color[i] = 0;
        v[i].clear();
    }
}
void solve()
{

    int n; cin>>n;
    int x, y;
    clears();
    vector<int> cnt1(n+5), cnt2(n+5);
    for(int i= 1; i<=n; i++) {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        cnt1[x] ++;
        cnt2[y] ++;
        if(cnt1[x] >=3 || cnt2[x] >=3){
            cout<<"NO\n";
            return;
        }
    }
    for(int i = 1; i<=n; i++){
        if(check[i] == true) continue;
        if(dfs(i, 1) ==  false) {
            cout<<"NO\n";
            return;
        }
    }

    cout<<"YES\n";

}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    #endif
    int t; cin>>t;
    while(t--)
    solve();
    return 0;
}
