/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll INF=1e5+7;
const ll MIN=- 1e5+7;
int tc;

ll tree[INF*4],a[INF];
vector<pair<int,int>>v[INF];
bool cmp(pair<int,int>a, pair<int,int>b){
    return a.second<b.second;
}
int check[INF];
void solve()
{
    int l,r,x,y;
    cin>>l>>r>>x>>y;
    // sort(v.begin(),v.end());
    // int lower = 0, higher = tc-1;
    // while(lower<=higher){
    //     int mid = lower + (higher-lower+1)/2;
    //     if(v[mid].first == x && v[mid].second<=r && v[mid].second>=l && check[mid]==0) {
    //         v[mid].first = y;
    //         check[mid]=1;
    //     }
    //     if(v[mid].first < x) lower = mid + 1;
    //     else higher = mid -1; 
    // }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    cin>>tc;
    for (ll t=1; t<=tc; t++) {
        cin>>a[t];
        v[i].push_back({a[t],t});
    }
    int n; cin>>n;
    while(n--)
    solve();
    sort(v.begin(),v.end(),cmp);
    for(auto x: v) cout<<x.first<<" ";
    return 0;
}