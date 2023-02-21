// Yet Another Problem About Pairs Satisfying an Inequality
/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll INF=2e5+7;
const ll MIN=- 1e5+7;
int n, arr[INF];
map<ll,vector<ll>>tree;
vector<ll> mergers(vector<ll>a, vector<ll>b){
    vector<ll>ans;
    ll i=0,j=0;
    while(i<a.size() && j<b.size()){
        if(a[i]<b[j]) {
            ans.push_back(a[i]);
            ++i;
        }else{
            ans.push_back(b[j]);
            ++j;
        }
    }
    while(i<a.size()) ans.push_back(a[i]),++i;
    while(j<b.size()) ans.push_back(b[j]),++j;
    return ans;
}
  
void buid(){
    for(ll i=n-1;i>0;i--){
        tree[i] = mergers(tree[i<<1], tree[i<<1|1]);
    }
}
ll getvl(int l, int r, int k){
    int cnt = 0;
    for(l+=n, r+=n;l<r;l>>=1, r>>=1){
        if(l&1) {
            int id = upper_bound(tree[l].begin(), tree[l].end(), k)-tree[l].begin();
            if(id<=tree[l].size()) cnt+=tree[l].size()-id;
            l++;
        }
        if(!(r&1)){
            int id = upper_bound(tree[r].begin(), tree[r].end(), k)-tree[r].begin();
             if(id<=tree[r].size()) cnt+=tree[r].size()-id;
            r--;
        }
    }
    if(l==r){
        int id = upper_bound(tree[l].begin(), tree[l].end(), k)-tree[l].begin();
         if(id<=tree[l].size()) cnt+=tree[l].size()-id;

    }
    return cnt;
    
}
void solve()
{
    cin>>n;
    ll k;
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        if(arr[i]<i+1) tree[i+n].push_back(arr[i]);
    }
    buid();
    ll cnt = 0;
    for(ll i=0;i<n;i++){
        if(arr[i]<i+1){
            cnt+=getvl(i+1, n, i+1);
        }
    }
    cout<<cnt<<"\n";
    tree.clear();

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) 
solve();
    return 0;
}