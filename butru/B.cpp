#include<bits/stdc++.h>
using namespace std;

const long long MAX = 1e6+ 7;
void solve()
{

    long long n; cin>>n;
    long long x; cin>>x;
    long long arr[n];
    for(int i = 0; i < n; i++) cin>>arr[i];
    long long s = 0, cnt = 0,ans = 0;
    for(int i = 1; i < (1<<n); i++){
        s = 1, cnt = 0;
        for(int j = 0; j < n; j++){
            if(i&(1<<j)){
                s = lcm(arr[j], s);
                cnt++;
            }
        }
        if(cnt&1){
            ans += x/s;
        }else ans -= x/s;
//        cout<<s<<" "<<ans<<" "<<cnt<<endl;
    }
    cout<<ans;
}
int main()
{

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

