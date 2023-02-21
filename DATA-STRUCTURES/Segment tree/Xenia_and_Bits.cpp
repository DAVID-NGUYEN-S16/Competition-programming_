/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll INF=3e5+7;
const ll MIN=- 1e5+7;
ll n, m,h,check=0; 
ll tree[INF*3];
// map<ll,ll> check;
void buid(){
    ll x = n/2;
    ll cs = x;
    for(ll i=n-1;i>0;i--){
        ll s = log2(i) + 1;
        if(h%2!=0) {
            if(s%2!=0) check=1;
            else check=0;
        }else{
            if(s%2==0) check=1;
            else check=0;
        }
    
        if(check == 1) {
            tree[i] = (tree[i<<1] | tree[i<<1|1]);
            // c
        }else {
            tree[i] = (tree[i<<1] ^ tree[i<<1|1]);
            // cout<<i<<" "<<tree[i]<<"\n";
        }
    }
}
void modify(ll id, ll vl){
    for(tree[id+=n]=vl;id>1;id>>=1){
        
         ll s = log2((id>>1))+1;
         if(h%2!=0) {
            if(s%2!=0) check=1;
            else check=0;
        }else{
            if(s%2==0) check=1;
            else check=0;
        }
         if(check==1) {
            tree[id>>1] = (tree[id] | tree[id^1]);
            // c
        }else {
            tree[id>>1] = (tree[id] ^ tree[id^1]);
        }
    }
}

void solve()
{ 
    cin>>n>>m;
    // h = sizeof(ll) * 8 - __builtin_clz(n);
    h=n;
    n = (ll)pow(2,n);
    ll x,y;
    for(ll i=0;i<n;i++) cin>>tree[i+n];
    buid();
    while(m--){
        cin>>x>>y;
        x--;
        if(n==2) {
             tree[n+x]=y;
             tree[1] = tree[n]| tree[n+1];
        }else modify(x,y);
        cout<<tree[1]<<"\n";
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