#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll MAX = 1e6 + 7;
const ll INF = 1e18 + 9;
const ll MOD = 1e9 + 7;
void solve(){
    ll l, r, x,a, b;
    cin>>l>>r>>x;
    cin>>a>>b;
    if(a==b){
        cout<<"0\n"; return;
    }

    ll rx = a + x, lx = a -x;
    if( rx  <= b || a - x >= b ) {
        cout<<"1\n";
        return;
    }
    if( rx <= r){
        ll du = r - x;
        ll du3 = du - l;
        if(b <= du ){
            cout<<"2\n"; return;
        }
        if( b >=du && b <= du + du3){
            cout<<"3\n"; return;
        }
    }
    if(lx >= l){
            ll du = l + x;
            ll du3 = r - du;
        if(b >= l+ x){

            cout<<"2\n"; return;
        }
        if(b>= l && b <= min(l + du3, r)){
            cout<<"3\n"; return;
        }
    }
    cout<<"-1\n";
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
    int t; cin>>t;
    while(t--)
        solve();
}
