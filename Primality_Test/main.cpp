#include<bits/stdc++.h>
using namespace std;
using u64 = uint64_t;
using u128 = __uint128_t;
u64 binpower(u64 base, u64 e, u64 mod){
    u64 res = 1;
    base %= mod;
    while(e){
        if( e&1 ) res = (u128)res * base %mod;
        base = (u128)base * base % mod;
        e>>=1;
    }
    return res;
}
bool check_composite(u64 n, u64 a, u64 d, long long s){
    u64 x = binpower(a, d, n);
    if(x == 1 || x == n-1) return false;
    for(long long r = 1; r < s; r++){
        x = (u128)x * x % n;
        if(x == n-1) return false;
    }
    return true;
}
bool MillerRabin(u64 n)
{
    if( n < 2 ) return false;
    long long r = 0;
    u64 d = n - 1;
    while((d & 1) == 0)
    {
        d >>= 1;    
        r++;
    }
    for(long long a: {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,325, 9375, 28178, 450775, 9780504 , 1795265022, 13, 19, 73, 193, 407521, 299210837}){
        if(n == a) return true;
        if(check_composite(n, a, d, r)) return false;
    }
    return true;
}
void solve()
{
    long long n; cin>>n;
    if(MillerRabin(n)) cout<<"YES\n";
    else cout<<"NO\n";
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    int t; cin>>t;
    while(t--)
    solve();
    return 0;
}