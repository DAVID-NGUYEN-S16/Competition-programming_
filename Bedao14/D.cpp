#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll MAX = 1e6 + 7;
const ll INF = 1e18 + 7;
const ll MOD = 1e9 + 7;
vector<ll>boi[MAX];

void process()
{
    for(int i = 2; i <= 10000; i++){
        for(long long j = i ; j <= i*i; j+=i){
            boi[i].push_back(j);
        }
    }
}
void solve()
{
    long long n; cin>>n;
     ll m = n*n;
     ll ans = (n+m)%MOD;
    for(long long i = 0; i < boi[n].size(); i++){
            for(int j = i+ 1; j < boi[n].size(); j++){
                if(lcm(boi[n][i], boi[n][j]) == m && __gcd(boi[n][i], boi[n][j]) == n){
                    ans = (ans + boi[n][i] + boi[n][j]) %MOD;
                }
            }
    }
    cout<<ans<<"\n";

}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    process();
    int t; cin>>t;
    while(t--)
    solve();
    return 0;
}



