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
const ll base = 311;
ll POW[INF], hasha[INF], hashb = 0, hashc = 0; 
ll getvl(int i, int j){
    return (hasha[j] - hasha[i-1]*POW[j-i+1]+MOD*MOD)% MOD;
}
void solve()
{
    string s;cin>>s;
    int lens = s.size();
    s = " "+s;
    string res1 = " AB", res2 =" BA";
    // pow
    POW[0]=1;
    for(int i=1;i<=lens;i++)
    POW[i] = (POW[i-1]*base)%MOD;
    for(int i=1;i<=2;i++){
        hashb = (hashb*base + res1[i]-'A'+1)%MOD;
        hashc = (hashc*base + res2[i]-'A'+1)%MOD;
    }
    for(int i=1;i<=lens;i++)
    hasha[i] = (hasha[i-1]*base +s[i]- 'A'+1)%MOD;
    set<int>v1, v2;

    // cout<<hashb<<" "<<hashc<<"\n";

    for(int i=1;i<=lens-1;i++){
        ll ans = getvl(i, i+1);
        // c
        if(hashb == ans ){
            v1.insert(i);
        }
        if(hashc==ans ) v2.insert(i);
        // cout<<ans<<" ";
    }
    if(v1.size()==0 || v2.size()==0){
        cout<<"NO\n"; return;
    }
    if(abs(*v1.rbegin()-*v2.begin())>=2|| abs(*v2.rbegin()-*v1.begin())>=2) cout<<"YES";
    else cout<<"NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //ll tc=1; cin>>tc;
    //for (ll t=1; t<=tc; t++) 
solve();
    return 0;
}