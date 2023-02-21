#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MAX = 1e6 + 7;
const long long MIN =  -1e6;
const long long MOD = 1e9 + 7;
const long long INF = 1e18 + 7;
const long long base = 31;
long long cost(long long a, long long b){
    // to a -> z - 'a' -> b;
    long long cs = abs('Z' - a) + 1 + abs(b - 'A');
    // to a -> 'a' -> z -> b
    cs = min(cs, abs(a - 'A' + 1 + 'Z' - b));
    return min(abs(a-b), cs );
}
//int cost(int x, int y) {
//    x = x - 'A';
//    y = y - 'A';
//    int ans = abs(x - y);
//    ans = min(ans, x + 1 + (25 - y));
//    ans = min(ans, (25 - x) + 1 + y);
//    return ans;
//}
void solve()
{

    long long n, m, ans = 0; cin>>n>>m;
    string s[n];
    for(int i = 0; i<n; i++) cin>>s[i];
    for(int i = 0; i < (n+1)/2; i++){
        for(int j = 0; j < (m+1)/2 ; j++){
            vector<char> tmp;
            tmp.push_back(s[i][j]);
            // Phải kiểm tra vì sẽ có trường hợp ra trùng
            if (m - 1 - j != j) tmp.push_back(s[i][m-j-1]);
            if (n - 1 - i != i) tmp.push_back(s[n-i-1][j]);
            if (n - 1 - i != i && m - 1 - j != j) tmp.push_back(s[n-i-1][m-j-1]);
            long long costs = 100000000;
            for(auto x: tmp) cout<<x<<" ";
            cout<<endl;
            for(char c = 'A'; c <= 'Z'; c++){
                long long cost_tmp = 0;
                for(auto x: tmp){
                    cost_tmp+= cost(x, c);
                }
                costs = min(costs, cost_tmp);
//                if(costs > cost_tmp){
//
//                }
            }
            ans+=costs;


        }
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
//    int t; cin>>t;
//	while(t--)
    solve();
    return 0;
}
