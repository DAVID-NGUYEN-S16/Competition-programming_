#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll base = 31;
const ll MAX = 1e6 + 7;
const ll MOD = 1e9 + 7;
ll hashs[MAX], hasha = 0, POW[MAX];
ll gethash(ll i, ll j){
    return hashs[j] - POW[j - i +1]*hashs[i-1];
}
void solve(){
    string a, s;
    cin>>a>>s;
    ll ns = s.size();
    ll na = a.size();
    s = "+" + s;
    a = "+" + a;
    POW[0] = 1;
    for(ll i = 1; i <= ns; i++){
        POW[i] = (POW[i-1] * base) % MOD ;
    }
    for(ll i = 1; i <= ns; i++){
        hashs[i] = (hashs[i-1]*base + s[i] - 'a' + 1) % MOD;
    }
    hasha = 0;
    for(ll i = 1; i <= na; i++){
        hasha = (hasha*base + a[i] - 'a' + 1) % MOD;
//        cout<<hasha*base <<" "<< a[i] - 'a' + 1<<endl;
    }
    ll cnt = 0;
//    cout<<gethash(1, 2) << " "<< hasha<<endl;
    for(ll i = 1; i + na - 1<= ns; i++){
//        cout<<gethash(i, i + na - 1) << " "<< hasha<<endl;
        if(gethash(i, i + na - 1) == hasha) cnt++;
    }
    cout<<cnt;


}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
