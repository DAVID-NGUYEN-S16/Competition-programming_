#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e18+7;
const ll INF=1e5+7;
const ll MIN=- 1e5+7;
const ll MAX= 10000001;
int prime[MAX];
unsigned long long cntdiv[MAX];
vector<unsigned long long>storePrime;
unsigned long long mas = 0;
// chú ý chống tràn 
void eratosthenes(){
    for(unsigned long long i = 2; i*i<MAX; i++){
        if(prime[i] ==0 ){
            for(unsigned long long j = i*i; j<MAX; j+=i){
                if(prime[j]==0) {
                    prime[j] = i;
                    // c
                }
            }
        }
    }
    for(ll i=2;i<MAX;i++) {
        if(!prime[i]) {
            storePrime.push_back(i);
            prime[i] = i;
        }
    }
}
unsigned long long coutdiv(unsigned long long x, unsigned long long p){
    unsigned long long cnt = 0, tmp=1;
    while(x/p>=tmp){
        tmp*=p;
        cnt+=x/tmp;
    }
    return cnt;
}
unsigned long long arr[MAX];
bool ok(unsigned long long n){         
    for(auto x: storePrime){
        if(cntdiv[x] == 0) continue;
        if(cntdiv[x] > coutdiv(n, x)) return false;
    }
    return true;
            
}
void solve()
{
    eratosthenes();
    // c
     unsigned long long n; cin>>n;
    for(unsigned long long i = 1; i<=n; i++) cin>> arr[i];
    sort(arr+1, arr+n+1);
    for(unsigned long long i = 0; i <n ;i++){
        for(unsigned long long j = arr[i] + 1; j<=arr[i+1]; j++){
            unsigned long long x = j;
            while(x>1){
                cntdiv[prime[x]]+=n-i;
                x /= prime[x];
            }
        }
    }

    // binary search
    unsigned long long l = 0, r = 1e13;
 
    while(l<=r){
        if(l==r) {
            // c
            cout<<l; break;
        }
        if(r -l ==1)if(ok(l)) {
            cout<<l; break;
        }
        unsigned long long mid = (l + r)/2;
        if(ok(mid)) r = mid;
        else l = mid+1;
    }

    // cout<<"\n"<<cntdiv[3]<<"\n";
    // cout<<coutdiv(4 ,2);
}

int  main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    freopen("factorial.inp", "r", stdin);
    freopen("factorial.out", "w", stdout);
    // #endif
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    //ll tc=1; cin>>tc;
    //for (ll t=1; t<=tc; t++) 
    solve();
    return 0;
}