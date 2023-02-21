/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+7;
void solve()
{
     char a[8] = {'R','O','Y','G','B','I','V'};
    //  ROYGRBIV
     int n; cin>>n;
    //  while(n--){
    //      for(int )
    //  }
    int j=0;
    string s;
    for(int i=0;i<n;i++){
        s=s+a[j];
        if(j==6) j=-1;
        j++;
    }
    if(s[n-1]=='R') s[n-1] = 'G';
    cout<<s;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    //ll tc=1; cin>>tc;
    //for (ll t=1; t<=tc; t++) 
solve();
    return 0;
}