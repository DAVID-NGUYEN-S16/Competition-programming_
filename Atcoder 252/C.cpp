#include<bits/stdc++.h>
using namespace std;
int cnt[150][150];
void solve()
{
    int n; cin>>n;
    string s;
    map<char, int>ans;
    for(int i  =1; i <= n; i++){
            cin>>s;
        for(int j = 0; j < s.size(); j++) {
                ans[s[j]]= max(ans[s[j]],j);
//                if(s[j] == '8') cout<<ans[s[j]]<<endl;
        }
    }
    int res = 1e9;
    for(char c = '1'; c<='9'; c++) res = min(res, ans[c]);
    cout<<res;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    solve();

}

