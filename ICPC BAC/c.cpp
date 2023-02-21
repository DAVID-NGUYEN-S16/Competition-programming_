#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e9+7;
const ll INF=1e5+7;
const ll MIN=- 1e5+7;
void solve()
{
    int n; 
    cin>>n;
    int arr[n];
    string s;
    for(int i = 0; i<n ; i++) {
        cin>>arr[i];
        // cout<<arr[i];
    }
    cin>>s;
    // cout<<s.size()<<"\n";
    map<char, vector<int>> mp;
    for(int i = 0; i<s.size(); i++){
        mp[s[i]].push_back(arr[i]);
    }
    for(auto x: mp){
        int ch = x.second[0];
        for(int i = 0; i<x.second.size(); i++){
            if(ch != x.second[i]){
                cout<<x.first<<" "<<x.second[i]<<"\n";
                cout<<"No\n"; return;
            }
        }
    }
    int check = 0;
    
    for(int i = 1; i<s.size(); i++){
        if(s[i]!=s[i-1] && arr[i] != arr[i-1]||s[i]==s[i-1] && arr[i] == arr[i-1]) continue;
        check =1; break;
    }
    if(check==1) cout<<"No\n";
    else cout<<"Yes\n";
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