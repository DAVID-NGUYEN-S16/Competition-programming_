#include<bits/stdc++.h>
using namespace std;
struct fenwick
{
    vector<long long>bit;
    long long n;
    fenwick(long long n_){
        bit = vector<long long>(n_ + 1, 0);
        n = n_;
    }
    void update(long long i, long long v){
        for(i; i <= n; i+= (i&-i)){
            bit[i]+=v;
        }
    }
    long long getvl(long long i){
        long long sum = 0;
        for(i; i >0; i -= (i&-i)) sum+=bit[i];
        return sum;
    }
};
void solve(){
    long long n, k; cin>>n>>k;
    vector<pair<long long, long long>> query(n);
    vector<fenwick> bits(k, fenwick(n));
    for(auto &[l, r]: query) cin>>l>> r;
    sort(query.begin(), query.end());
    for(int i = 0; i < n; i++){
        for(int j = k-1; j>0; j--){
            long long vl = bits[j-1].getvl(query[i].second-1);
            bits[j].update(query[i].second, vl);
        }
        bits[0].update(query[i].second, 1);
    }
    cout<<bits[k-1].getvl(n)<<endl;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
 }
