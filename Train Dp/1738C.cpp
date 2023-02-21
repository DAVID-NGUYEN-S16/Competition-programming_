#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000][2][2][2];
bool f(int c, int l, int state, bool as, bool bs)
{

    if(c == 0 && l == 0){
        return as;
    }
    if(dp[c][l][state][as][bs] != -1) return dp[c][l][state][as][bs];
    int ans1 = 0, ans2 = 0;
    if(state){
        if(c > 0 ) {
            if(as)
                ans1 = f(c-1, l , not(state), as, bs);
            else ans1 = f(c-1, l, not(state), 0, bs);
        }
        if(l > 0) {
            if(as)
                ans2 = f(c, l-1 , not(state), 0, bs);
            else ans2 = f(c, l-1, not(state), 1, bs);
        }
    }else {
        ans1 = 1, ans2 = 1;
        if(c > 0 ) {
            if(bs)
                ans1 = f(c-1, l , not(state), as, bs);
            else ans1 = f(c-1, l, not(state), as, 0);
        }
        if(l > 0) {
            if(bs)
                ans2 = f(c, l-1 , not(state), as, 0);
            else ans2 = f(c, l-1, not(state), as, 1);
        }
    }
//    cout<<as<<" "<<state<<endl;
    if(state) return dp[c][l][state][as][bs] = max(ans1, ans2);
    else return dp[c][l][state][as][bs] = min(ans1, ans2);

}
void solve()
{
    int n;
    cin>>n;
    int c = 0, l = 0;
    int x;
    for(int i = 1; i <= n; i++){
        cin>>x;
        if(x&1) l++;
        else c++;
    }
    memset(dp, -1, sizeof(dp));
    if(f(c, l , 1, 1, 1)) cout<<"Alice\n";
    else cout<<"Bob\n";
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    int t; cin>>t;
    while(t--) solve();
}
