#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MAX = 1e6 + 7;
const long long MIN =  -1e6;
const long long MOD = 1e9 + 7;
const long long INF = 1e18 + 7;
const long long base = 31;
map<long long, long long>hash_code;
void solve()
{
    long long n; cin>>n;
    string s;
    long long ans = 0;
    for(long long i = 1; i <= n; i++){
        cin>>s;
        long long has = 0;
        // encode string 
        for(auto x: s) has ^= 1<<(x - 'a');
        ans += hash_code[has];
        for(long long j = 0; j < 26; j++) ans += hash_code[has^(1<<j)];
        hash_code[has]++;
    }
    cout<<ans;

 }
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    #endif
    // int t; cin>>t;
    // while(t--)
    solve();
    return 0;
}