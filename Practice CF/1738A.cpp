#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e9+7;
const ll INF=1e5+7;
const ll MIN=- 1e5+7;

void solve()
{
    ll n; 
    cin>>n;
    vector<ll>arr(n+5);
    ll x, y;
    ll ans = 0;
    multiset<ll>sto[100];
    for(ll i=1;i<=n;i++) {
        cin>>x;
        arr[i] = x;
    }
    for(ll i=1;i<=n;i++) {
        cin>>x;
        sto[arr[i]].insert(x);
        ans+=x;
    }
    ll i = sto[0].size(), j = sto[1].size();
    ll sum = 0, mis = min(*sto[0].begin(),*sto[1].begin());

    while(sto[0].size() != 0 && sto[1].size() !=0  ){
        sum += ( *sto[0].rbegin() + *sto[1].rbegin())*2;
        sto[0].erase(sto[0].find(*sto[0].rbegin()));
        sto[1].erase(sto[1].find(*sto[1].rbegin()));
    }
    for(auto k: sto[0]) sum+=k;
    for(auto k: sto[1]) sum+=k;
    if(i==j) sum -=mis;

    cout<<sum<<"\n";
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