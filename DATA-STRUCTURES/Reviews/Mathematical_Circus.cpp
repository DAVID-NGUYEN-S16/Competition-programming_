/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e9+7;
const ll INF=2e5+7;
const ll MIN=- 1e5+7;
void solve()
{
    ll n, k; cin>>n>>k;
    ll bc = 0;
    bool check[INF];
    memset(check, false, sizeof(check));
    vector<pair<ll,ll>>ans;
    if(k%4==0){
        cout<<"No\n";
        return ;
    }
    cout<<"YES\n";
    if(k%4==2){
        int i = 1;
        int j = 2;
        cout<<2<<" "<<1<<"\n";
        for(int i=1;i<n/2;i++){
            if(i%2!=0) {
                j++;
                cout<<j<<" "<<j+1<<"\n";
            }else{
                j+=3;
                cout<<j<<" "<<j-1<<"\n";
            }
        }
        return;
    }else{
        int j = 0;
        for(int i=1;i<n/2;i++){
            cout<<j+i<<" "<<j+i+1<<"\n";
            j++;

        }
        return ;
    }

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