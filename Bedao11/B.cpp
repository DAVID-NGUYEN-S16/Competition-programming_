#include<bits/stdc++.h>
using namespace std;
const long long MAX = 1e6+7;
vector<pair<int,int>> query(MAX);
vector<long long> sumW(MAX), sumXW(MAX);
int n;

void solve()
{
    cin>>n;
    for(int i = 1; i <= n; i++) {
            cin>>query[i].first>>query[i].second;
            sumW[i] = sumW[i-1] + query[i].second;
            sumXW[i] = sumXW[i-1] + query[i].second * query[i].first;
    }
    int q; cin>>q;
    while(q--){
        int l, r; cin>>l>>r;
        cout<<query[r].first * (sumW[r-1] - sumW[l-1]) - (sumXW[r-1] - sumXW[l-1])<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}
