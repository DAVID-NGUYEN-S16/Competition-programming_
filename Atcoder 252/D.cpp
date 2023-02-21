#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e18+7;
const ll MAX = 1e6+7;
int cnt[150][150];
void solve()
{
    ll n; cin>>n;
    vector<ll> arr(MAX), pref(MAX);
    ll mas = 0;
    for(int i = 1; i <= n; i ++){
        cin>>arr[i];
        pref[arr[i]]++;
        mas = max(arr[i], mas);
    }
    for(int i = 1; i <= mas; i++){
        pref[i] += pref[i-1];
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans+= pref[arr[i]-1] * (n - pref[arr[i]]);
    }
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    solve();

}


