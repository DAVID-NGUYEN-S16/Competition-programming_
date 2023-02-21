#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 1e5 + 7;
const ll INF = 1e18 + 7;

void solve()
{
    ll n, q; cin>>n>>q;
    ll arr[n+5];
    for(ll i = 1; i <= n; i++){
        cin>>arr[i];
    }
    vector<ll>win[n+5];
    deque<ll> d;
    for(ll i = 1; i <= n; i++) d.push_back(i);
    for(ll i = 1; i <= n; i++){
        ll x = d.front(); d.pop_front();
        ll y = d.front(); d.pop_front();
        if(arr[x] > arr[y]){
            win[x].push_back(i);
            d.push_front(x);
            d.push_back(y);
        }else{
            win[y].push_back(i);
            d.push_front(y);
            d.push_back(x);
        }
    }
    ll x, k;
    while(q--)
    {
        cin>>x>>k;
        ll id = upper_bound(win[x].begin(), win[x].end(), k) - win[x].begin();
        if(arr[x] == n) id+= max(0LL, k - n);
        cout<<id<<"\n";
    }

}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    int t; cin>>t;
    while(t--)
    solve();
}
