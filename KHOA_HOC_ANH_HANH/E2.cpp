#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e9+7;
const unsigned long long INF=1e19+7;
const unsigned long long MAX=2.5e6+7;
long long cntDiv[MAX+1];
vector<unsigned long long > prime;
vector<pair<unsigned long long, int>> storeE;
unsigned long long pw(long long a, unsigned long long b){
    unsigned long long ans = 1;
    for(int i = 1; i<=b; i++){
        if(INF/ans<a) return INF;
        ans*=a;
    }
    return ans;
}
void prepare(){
    for(int i  =1; i<=MAX; i++)
        for(int j = i; j<=MAX; j+=i) cntDiv[j]++;
    for(int i = 2; i<=MAX; i++) if(cntDiv[i] == 2) prime.push_back(i);

    for(int i = 1; i<=MAX; i++){
        unsigned long long p = pw(i, cntDiv[i]);
        if(p<INF) storeE.push_back({p, i});
    }
    sort(storeE.begin(), storeE.end());
    
}
unsigned long long chec_chinh_phuong(unsigned long long n){
    unsigned long long x =  sqrt(n);
    if(x*x == n) return x;
    else return -1;
}
bool checkPrime(unsigned long long n){
    for(auto x: prime) {
        if(x*x > n) return true;
        if(n%x==0) return false;
    }
    return false;
}
long long solve(unsigned long long e)
{
    // check chinh phuong 
    long long res = -1;
    unsigned long long avg = chec_chinh_phuong(e);
    if(avg >= 0 && checkPrime(avg)) res = avg;
    long long id =lower_bound(storeE.begin(), storeE.end(), make_pair(e, 0)) - storeE.begin();
    if(id <storeE.size() && storeE[id].first == e){
        res = storeE[id].second;
    }
    
    return res;

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    freopen("divpow.inp", "r", stdin);
    freopen("divpow.out", "w", stdout);
    prepare();
    // for(auto x: storeE) cout<<x.first<<" "<<x.second<<"\n";
    // for(auto x: cntDiv)
    // for(int i = 1; i<=100; i++) cout<<i<<" "<<cntDiv[i]<<"\n";
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) {
        unsigned long long x;
        cin>>x;
        cout<<solve(x)<<" ";
    }
    
    return 0;
}