/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e9+7;
const ll INF=1e9+7;
const ll MIN=- 1e5+7;
void solve()
{
    int n; cin>>n;
    int arr[n+5];
    int mis = INF, id = 0;
    map<int,int>mp;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        if(mis>arr[i]){
            id = i;
            mis = arr[i];
        }
    }
    if(n%2!=0) cout<<"Mike\n";
    else {
        if(id%2==0) cout<<"Mike\n";
        else cout<<"Joe\n";
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