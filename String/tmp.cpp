
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, k; 
    cin>>n>>k;
    long long ans = 1e18;
    if(n <= k ){
        cout<<1<<"\n"; return;
    }
    for(int i = sqrt(k); i > 0; i--){
        long long x = i;
        long long pw = 0;

        while(x <= k && n % x == 0 ){
            pw = x;
            x+=x;
            cout<<pw<<"++\n";
        }
        if(pw != 0 ) {
                ans = min(ans, n/pw);
                cout<<ans<<endl;
//                couCt<<ans<<" ** "<<n/pw<<endl;
        }
    }
    cout<<ans;

}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    solve();
}

