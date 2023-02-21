#include<bits/stdc++.h>
using namespace std;
const long long MAX = 1e5 + 7;
bool dp[350][350][350];
bool check[350][350][350];
string s;
bool f(int l, int r, int k1, int k2, int turn){
   if( check[l][r][k1] ) return dp[l][r][k1];
   if( k1 == 0) return true;
   if( k2 == 0) return false;
   check[l][r][k1] = true;
   bool& ans = dp[l][r][k1];
   if(turn  == 0){
       if(f(l+1, r, k1 - (s[l] == 'B'), k2, 1) == 0) return ans = false;
       if(f(l, r - 1, k1 - (s[r] == 'B'), k2, 1) == 0) return ans = false;
       return ans = true;
   }else{
       if(f(l+1,   r, k1, k2 - (s[l] == 'B'), 0) == 1) return ans = true;
       if(f(l, r - 1, k1, k2 - (s[r] == 'B'), 0) == 1) return ans = true;
       return ans = false;
   }
}
void solve(){
   int n, k;
    cin>>n>> k;
    cin>>s;
    if(f(0,n-1, k, k, 0) == false) cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
