#include<bits/stdc++.h>
using namespace std;
long long getvl(long long n, long long a, long long b){
    return (n/a)*min(a, b) + min(n%a, b-1);
}
void solve(){
    long long n, a, b; cin>>n>>a>>b;
    cout<<max(0ll,getvl(n, a, b) - getvl(a-1, a, b));
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
//    int t; cin>>t;
//    while(t--)
    solve();
    return 0;
}

