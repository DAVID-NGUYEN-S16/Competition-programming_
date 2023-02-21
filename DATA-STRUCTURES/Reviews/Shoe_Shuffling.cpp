/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e9+7;
const ll INF=1e5+7;
const ll MIN=- 1e5+7;
void solve()
{
    int n; cin>>n;
    map<int,vector<int>>v;
    set<int>st;
    int s[n+5],ans[n+5];
    for(int i=1;i<=n;i++){
        cin>>s[i];
        v[s[i]].push_back(i);
        st.insert(s[i]);
    }
    for(auto x: st){
        if(v[x].size()>1){
            int id = v[x].size()-1;
            for(int i=0;i<v[x].size();i++){
                ans[v[x][i]] = v[x][id];
                id--;
            }
        }else{
            cout<<"-1\n"; return;
        }
    }
    for(int i=1;i<n;i++){
        if(ans[i]==i) swap(ans[i], ans[i+1]);
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<"\n";
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