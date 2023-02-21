#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e9+7;
const ll INF=10001001;
const ll MIN=- 1e5+7;
int  pw(int  a, int  k){
    int  res = 1;
    for(int i = 1; i<=k; i++){
        if(INF/ a < res) return INF;
        res*=a;
    }
    return res;
}
// map<int , int >res;
// int  res[INF];
int  sum(int  r, int  k){
    int  res = 0;
    for(int  i =1; i<=r; i++) {
        res += r/i - r / pw(i, k);
        // cout<<res<<" ";
    }
    // res[i] = res[i-1] +  abs(r/i - r/pw(i, k));
    return res;
}
void solve()
{
    int  l, r, k; cin>>l>>r>>k;
    cout<<sum(r, k) -  sum(l-1, k);
    // sum(r, k);
    // cout<<res[r] - res[l-2];
    // cout<<pw(2, 5);
    // cout<<res[r]<<" "<< res[l-1]<<"\n";
    // for(int i = 1; i<=r; i++){
    //     cout<<res[i]<<" ";
    // }

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    freopen("divexp.inp", "r", stdin);
    freopen("divexp.out", "w", stdout);
    // #endif
    //ll tc=1; cin>>tc;
    //for (ll t=1; t<=tc; t++) 
    solve();
    return 0;
}