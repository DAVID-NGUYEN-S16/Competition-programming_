/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll INF=1e5+7;
const ll MIN=- 1e5+7;
int arr[INF];
vector<pair<int,int>>v;
void solve()
{
    int n; cin>>n;
    // arr[0]=1;
    int old = 0;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        v.push_back({old+1, arr[i]+old});
        old = old + arr[i];
    } 
    int m,x; cin>>m;
    // for(auto x: v) cout<<x.first<<" "<<x.second<<"\n";
    while(m--){
        cin>>x;
        int l = 0, r =v.size()-1, ans = 0;;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(x >= v[mid].first && x<=v[mid].second) {
                ans = mid+1;
                break;
            }
            if(x<v[mid].first) r = mid-1;
            else l = mid+1;
        }
        cout<<ans<<"\n";
    }

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