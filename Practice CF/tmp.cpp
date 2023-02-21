#include<bits/stdc++.h>
using namespace std;
const long long MAX = 1e6+7;
int f[11][10000];
int n, k;
struct fenwick {
    int bit[100001];
    void update(long long i, long long v){
        
        for(;i>0;i-=i&-i){
            bit[i]+=v;
        }
    }
    long long gevl(long long i){
        long long sum = 0;
        for(;i<=n;i+=i&-i)  sum+=bit[i];
        return sum;
    }
}bits[11];
void solve(){
    cin>>n>>k;

    vector<pair<int, int>>a(n);

    for(int i = 0; i<n; i++) cin>> a[i].first>>a[i].second;
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++) cout<<a[i].first<<" "<<a[i].second<<"\n";
    for(int i = 0; i < n; i++){
        for(int len = 1; len <= k ; len++){
            if(len == 1) f[len][i] = 1;
            else f[len][i] = bits[len-1].gevl(a[i].second);
            bits[len].update(a[i].second, f[len][i]);
        }
    }
    cout<<bits[k].gevl(n+1)<<endl;


}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    solve();



}
