#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll MAX = 1e6 + 7;
const ll INF = 1e18 + 7;
const ll MOD = 1e9 + 7;
void solve()
{
    int n, q; cin>>n>>q;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin>>arr[i];
    sort(arr.begin(), arr.end());
    while(q--){
        int x;
        cin>>x;
        int before = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        if(before < n && x >= arr[0]) cout<<"Yes\n";
        else cout<<"No\n";
    }

}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    solve();
    return 0;
}


