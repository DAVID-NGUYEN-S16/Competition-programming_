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
void solve()
{
    int n, k; cin>>n>>k;
    // for(int i=1;i<)
    string s; cin>>s;
    int fis = n, las =0, cnt1 = 0, add1=0;
    for(int i=0;i<n;i++){
        if(s[i]!='1') continue;
        if(fis==n) fis = i;
        las = i;
        cnt1++;
    }
    if(cnt1 > 0 && (n-las-1)<=k){
        k-=(n-las-1);
        cnt1--;
        add1++;
    }
    if(cnt1 > 0 && fis <= k){
        cnt1--;
        add1+=10;
    }
    cout<<11*cnt1+add1<<"\n";
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