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
    ll n; cin>>n;
    vector<int>arr(n);
    int check5 = 0;
    for(auto & x: arr) {
        cin>>x;
        if( x % 5 == 0) check5 = 1;
    }
    if(check5){
        for(auto& x: arr){
            x += x % 10;
        }
        if(*max_element(arr.begin(), arr.end()) == * min_element(arr.begin(), arr.end())) cout<<"YES\n";
        else cout<<"NO\n";
        return;
    }
    bool check1 = false, check2 = false;
    for(auto x: arr){
        while( x % 10 != 2){
            x += x % 10;
        }
        if(x % 20 == 2) check1 = true;
        else check2 = true;
    }
    if((check1&check2)) cout<<"NO\n";
    else cout<<"YES\n";

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