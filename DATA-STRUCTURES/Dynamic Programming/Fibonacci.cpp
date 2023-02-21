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
map<ll, ll>F;

ll Fibon(int n){
    if(F[n]==0){
        if(n<=1) F[n]=1;
        else F[n] = (Fibon(n-2)%MOD + Fibon(n-1)%MOD)%MOD;
    }
    return F[n]%MOD;
}
void solve()
{
    ll n; cin>>n;
    cout<<Fibon(n)<<"\n";
    F[1]=F[0]=1;
    for(int i=2;i<=n;i++){
        F[i] =( F[i-2]%MOD+F[i-1]%MOD)%MOD;
        F[i]%=MOD;

    }
    cout<<F[n]<<"\n";
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