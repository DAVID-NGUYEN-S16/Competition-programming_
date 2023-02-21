/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e9+7;
const ll INF=1e5+7;
const ll MIN=- 1e5+7;
ll n,arr[INF], cnt = 0;
vector<int>tree[4*INF];
void meger(vector<int> a, vector<int>b,vector<int> &ans){
    int i = 0, j = 0;
    while(i<a.size() && j < b.size()){
        if(a[i]<b[j]) {
            ans.push_back(a[i]);
            i++;
        }else{
            ans.push_back(b[j]);
            j++;
        }
    }
    while(i<a.size()) ans.push_back(a[i]), i++;
    while(j<b.size()) ans.push_back(b[j]), j++;
}
void buid(ll id, ll l, ll r){
    if(l>r) return;
    if(l==r) {
        tree[id].push_back(arr[l]);
        return;
    }
    ll mid = (l+r)/2;
    buid(id*2+1, l, mid);
    buid(id*2+2, mid+1, r);
    meger(tree[id*2+1], tree[id*2+2], tree[id]);
}
ll getvl(ll id, ll l, ll r, ll lx, ll rx, ll vl){
    if(l>rx|| r<lx) return 0;
    if(tree[id].back()<=vl) return 0;
    if(l>=lx && r<=rx){
        int i = upper_bound(tree[id].begin(), tree[id].end(), vl) - tree[id].begin();
        return tree[id].size()-i;
    }
    
    ll mid = ( l + r )/2;
    return getvl(id*2+2, mid+1, r, lx, rx, vl) + getvl(id*2+1, l, mid, lx, rx, vl);
    

}
void solve()
{
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    buid(0, 0, n-1);
    cout<<0<<" ";
    for(ll i=1;i<n;i++){
        if(arr[i]==n) cout<<0<<" ";
        else  cout<<getvl(0,0, n-1, 0, i-1, arr[i] )<<" ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //ll tc=1; cin>>tc;
    //for (ll t=1; t<=tc; t++) 
    solve();
    return 0;
}