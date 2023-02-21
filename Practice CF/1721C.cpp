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
    int arr[n+5], brr[n+5];
    vector<int> ans1, ans2;
    ll mas = 0;
    map<int, int> mp1, mp2;
    for(int i = 1; i <= n; i++)
        cin>>arr[i];
    for(int i = 1; i <= n; i++){
        cin>>brr[i];
    }
    int ls = n;
    for(int i = n; i >0; i--){
        int id = lower_bound(brr+1, brr+n+1, arr[i]) - brr;
        ans1.push_back(brr[id] - arr[i]);
        ans2.push_back(brr[ls] - arr[i]);
        if(id == i) ls  = i -1;
    }
    for(int i = ans1.size()-1; i >=0; i--) cout<<ans1[i]<<" ";
    cout<<endl;
    for(int i = ans2.size()-1; i >=0; i--) cout<<ans2[i]<<" ";
    cout<<endl;
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