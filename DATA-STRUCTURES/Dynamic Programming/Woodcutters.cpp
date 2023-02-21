/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
#define f first;
#define s second;
const ll MOD=1e9+7;
const ll INF=1e5+7;
const ll MIN=- 1e5+7;

void solve()
{
    int n; cin>>n;
    vector<pair<int,int>>p;
    int x, y;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        p.push_back({x,y});
    }
    sort(p.begin(), p.end());
    int cnt = 1, l  = p[0].first - p[0].second,r = p[0].first;
    cout<<l<<" "<<r<<"\n";
    for(int i = 1;i<p.size();i++){
        if(p[i].first>r && p[i].first - p[i].second >r) {
            cnt++;
            r = p[i].first;
            cout<<p[i].first<<" "<<p[i].second<<" "<<l<<" "<<r<<"\n";
        }else if(p[i].first > r  && p[i].first + p[i].second > r){
            cnt++;
            r = p[i].first + p[i].second;
            cout<<p[i].first<<" "<<p[i].second<<" "<<l<<" "<<r<<"\n";
        }else {
            if(p[i].first>=l && p[i].first<=r) cnt--;
            if(r < p[i].first) r = p[i].first;
        }
    }
    cout<<cnt<<"\n";
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