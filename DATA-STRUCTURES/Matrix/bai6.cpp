/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=100;
const ll INF=1e5+7;
const ll MIN=- 1e5+7;
struct Matrix{
    ll m[3][3];
};
Matrix I;
ll n;
Matrix operator *(Matrix a, Matrix b){
    Matrix ans;
    ans.m[1][1]=ans.m[1][2]=ans.m[2][1]=ans.m[2][2]=0;
    for(ll i=1;i<=2;i++){  
        for(ll j=1;j<=2;j++){ 
            for(ll k=1;k<=2;k++){
                ans.m[i][j] += ((a.m[i][k])%MOD*(b.m[k][j])%MOD)%MOD;
                ans.m[i][j]%=MOD;
            }
        }
    }
    return ans;
}
Matrix PINPOW (Matrix a, ll p){
    if(p==1) return a;
    if(p==0) return I;
    Matrix c = PINPOW(a, p/2);
    if(p%2==0){
        return c*c;
    }else return c*c*a;
}
void solve()
{
    cin>>n;
    Matrix a;
    for(ll i=1;i<=2;i++){
        for(ll j=1;j<=2;j++){
            if(i==j) I.m[i][j]=1;
            else I.m[i][j]=0;
        }
    }
    a.m[1][1]=2;a.m[1][2]=3;a.m[2][1]=1;a.m[2][2]=2;
    Matrix ans = PINPOW(a, n-1);
    // for(int i=1;i<=2;i++){
    //     for(int j=1;j<=2;j++){
    //         cout<<ans.m[i][j]<<" \n";
    //     }
    // }
    ll res = ((ans.m[1][1]*2+ans.m[1][2])*2)%100;
    if(res<=9){
        cout<<0<<res<<"\n";
    }else cout<<res<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) 
solve();
    return 0;
}