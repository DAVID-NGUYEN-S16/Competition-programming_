#include<bits/stdc++.h>

using namespace std;
const long long MAX  = 4e6;
/*
    + Lưu ý từ bài này:
    + Tắt đề: kiểm tra một số nguyên tố có được tạo  nên từ
    các số nguyên tố liên tiếp hay không : vd 30 = 2 * 3* 5
    + Mà các số nguyên tố tạo thành đó nó phải khác nhau và không có số nguyên
    tố nào ở giữa các nguyên tố tạo thành đó
    -----------------------------------------------------------
    Giải:
    + Ta chia làm ta trường hợp
     1. n là số nguyên tố --> check bằng Miller brabin
     2. n được tạo nên từ 2 số nguyên tố liên tiếp --> check bằng sqrt(n) * sqrt(n) == n
     3. n được tạo thành từ 3 số nguyên tố liên tiếp --> ta check hêt tất cả các trường hợp
     sử dụng sàng nguyên tố.
*/
using u64 = uint64_t;
using u128 = __uint128_t;
u64 binpower(u64  base, u64 e, u64 mod){
    u64 res = 1;
    base %= mod;
    while(e){
        if(e&1) res = (u128)res* base %mod;
        base = (u128)base * base %mod;
        e >>=1;
    }
    return res;
}
bool check_composite(u64 n, u64 a, u64 d,  int s){
    u64 x = binpower(a, d, n);
    if(x == 1|| x == n-1) return false;
    for(long long r = 1; r < s; r++){
        x = (u128)x*x%n;
        if(x == (n-1)) return false;
    }
    return true;
}
bool MillerRabin(u64 n){
    if(n < 2) return false;
    for(long long a:{2, 3,5,7,11,13,17, 19, 23, 29, 31,37}){
        if( n % a == 0 && n != a) return false;
    }
    int r = 0;
    u64 d = n-1;
    while(!(d&1)){
        d>>=1;
        r++;
    }
    for(long long a:{2, 3,5,7,11,13,17, 19, 23, 29, 31,37}){
        if(n == a) return true;
        if(check_composite(n,a,d,r)) return false;
    }
    return true;
}
vector<int > primes;
vector<unsigned long long> primes_mutil;
void prepare(){
    vector<bool > check(MAX);
    for(long long i = 2; i < MAX; i++){
        if(!check[i]){
            for(long long j = i * i; j < MAX; j += i){
                check[j] = true;
            }
            primes.push_back(i);
        }
    }
    unsigned long long limits = 1000000000;
    limits *= limits * 10;
    for(long long  i =0; i < primes.size(); i++){
            unsigned long long ans = 1;
            for(long long j = i ; j < primes.size(); j++){
                if(ans > limits/ primes[j]) break;
                ans *= primes[j];
                primes_mutil.push_back(ans);
            }
    }
    sort(primes_mutil.begin(), primes_mutil.end());
}
// check truong hop  2
bool check_specal(unsigned long long n){
    if( n < 1e12) return false;
    unsigned long long m = sqrt(n) + 1, next1 = 0, next2 = 0;
    for(int i = 0; ; i++){
        unsigned long long x = m + i;
        if(MillerRabin(x)){
                next1 = x;
                break;
        }

    }
    for(int i = -1; ; i--){
        unsigned long long x = m + i;
        if(MillerRabin(x)){
            next2 = x;
            break;
        }
    }
    return next1 * next2 == n;

}
// check truong hop 3
bool have_prime(unsigned long long n){
    long long id = lower_bound(primes_mutil.begin(), primes_mutil.end(), n) - primes_mutil.begin();
    if(id >= primes_mutil.size()) return false;
    if( id < primes_mutil.size() && primes_mutil[id] == n) return true;
    else return false;
}
void solve()
{
    unsigned long long n; cin>>n;
    if(have_prime(n) || MillerRabin(n)|| check_specal(n) ) cout<<"NICE\n";
    else cout<<"UGLY\n";
}
int main()
{

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    prepare();
    int t; cin>>t;
    while(t--)
    solve();

}
