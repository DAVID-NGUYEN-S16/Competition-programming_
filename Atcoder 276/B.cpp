#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long MAX = 1e6 + 7;
const long long INF = 1e18 + 7;
const long long MOD = 1e9 + 7;
void solve()
{

    int n, m; cin>>n>>m;
    int x, y;
    set<int> v[n+5];
    for(int i = 1; i <= m; i++){
        cin>>x>>y;
        v[x].insert(y);
        v[y].insert(x);

    }
    for(int i = 1; i<= n; i++){
        cout<<v[i].size()<<" ";
        for(auto x: v[i]) cout<<x<<" ";
        cout<<"\n";
    }
}
int main()
{

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

