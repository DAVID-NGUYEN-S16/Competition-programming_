/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
const ll INF=1e5+7;
const ll MIN=- 1e5+7;
struct Matrix
{
    ll m[3][3];
};
Matrix operator *(Matrix a, Matrix b){
    Matrix ans;
    ans.m[1][1]=ans.m[1][2]=ans.m[2][1]=ans.m[2][2]=0;
    for(ll i=1;i<=2;i++){  
        for(ll j=1;j<=2;j++){ 
            for(ll k=1;k<=2;k++){
                ans.m[i][j] += ((a.m[i][k]%MOD)*(b.m[k][j]%MOD))%MOD;;
                ans.m[i][j]%=MOD;
            }
        }
    }
    return ans;
}
Matrix luythua (Matrix a, ll p){
    Matrix ans, I;
    I.m[1][1]=I.m[2][2] =1;
    I.m[1][2]=I.m[2][1] = 0;
    if(p==1) return a;
    if(p==0) return I;
    ans =a;
    Matrix c = luythua(a, p/2);
    if(p%2==0){
        return c*c;
    }else return c*c*a;
}
ll Binpow(int a, int p){
    if(p==1) return a;
    if(p==0) return 1;
    int tmp = Binpow(a,p/2);
    if(p%2==0) return tmp*tmp;
    if(p&2) return tmp*tmp*a;
}
void solve()
{
    ll n; cin>>n;
    Matrix g, ans, u;
    g.m[1][1]=1;
    g.m[1][2]=1;
    g.m[2][1]=1;
    g.m[2][2]=0;
    ans = luythua(g, n-1);
    cout<<(ans.m[1][1]%MOD+ans.m[1][2]%MOD)%MOD<<"\n";
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<ans.m[i][j]<<" ";
    //     }
    //     cout<<"\n";
    //     }
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