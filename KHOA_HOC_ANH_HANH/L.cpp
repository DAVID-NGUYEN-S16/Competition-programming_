#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e9+7;
const ll INF=1e18+7;
const ll MAX=1e7+7;
const ll MIN=- 1e5+7;
bool isPrime[MAX];
vector<long long> prime;
int eratosthenes(long long L, long long R){
    for (long long i = 2; i * i <= R; ++i) {
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i) {
            isPrime[j - L] = true;
        }
    }
    long long cnt = 0;
    if (1 >= L) {  
        isPrime[1 - L] = true;
    }

    for (long long x = L; x <= R; ++x) {
        if (!isPrime[x - L]) {
            cnt++;
        }
    }
    return cnt;
}

void solve()
{
    long long l, r; cin>>l>>r;

    cout<<eratosthenes(l, r);

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    freopen("eratosthene.inp", "r", stdin);
    freopen("eratosthene.out", "w", stdout);
    // #endif
    //ll tc=1; cin>>tc;
    //for (ll t=1; t<=tc; t++) 
    solve();
    return 0;
}