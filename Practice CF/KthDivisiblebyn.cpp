/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll INF=1e5+7;
const ll MIN=- 1e5+7;
void solve()
{
    int n, k; cin>>n>>k;
    // if(k>n) cout<<k<<"\n";
    // else{
        int x = k%(n-1),y=k/(n-1);
        // cout<<x<<" "<<y<<"\n";
        if(x==0) x--;
        cout<<y*n+x<<"\n";
    // }
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