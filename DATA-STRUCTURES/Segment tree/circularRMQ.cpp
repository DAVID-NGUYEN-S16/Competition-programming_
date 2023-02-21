/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll INF=3e5+7;
const ll INFs=1e18;
const ll MIN=- 1e5+7;
ll a[INF];
ll tree[INF*4], lazy[INF*4];
vector<ll>  convert(string s){
    vector<ll>v;
    stringstream ss(s);
    string k;
    while(ss>>k){
        int n = stoi(k);
        v.push_back(n);
        // cout<<n<<" ";
    }
    return v;
}
void buid(ll id, ll l, ll r){
    if(l>r) return;
    if(l==r) {
        tree[id] = a[l];
        return;
    } 
    int mid = (l+r)/2;
    buid(id*2, l, mid);
    buid(id*2+1, mid+1, r);
    tree[id] = min(tree[id*2], tree[id*2+1]);
    // cout<<tree[id]<<"\n";
}
void update(ll id, ll l , ll r, ll u, ll v, ll k){
    if(lazy[id]!=0){
        tree[id]+=lazy[id];
        if(l!=r){
            lazy[id*2] += lazy[id];
            lazy[id*2+1] += lazy[id];
        }
        lazy[id]=0;
    }
    if(u>r || v< l ) return;
    if(l>=u && r<=v){
        tree[id] += k;
        if(l!=r){
            lazy[id*2] += k;
            lazy[id*2+1] += k;
        }
        lazy[id]=0;
        return;
    }
    int mid = (l+r)/2;
    update(id*2, l, mid, u, v,k);
    update(id*2+1, mid+1, r, u, v, k);
    tree[id] = min(tree[id*2], tree[id*2+1]);
}
ll getvl(int id, int l , int r, int u, int v){
    if(lazy[id]!=0){
        tree[id]+=lazy[id];
        if(l!=r){
            lazy[id*2] += lazy[id];
            lazy[id*2+1] += lazy[id];
        }
        lazy[id] = 0;
    }
    if(l>=u && r<=v) return tree[id];
    if(l>v || r<u) return INFs;
    int mid = (l+r)/2;
    return min(getvl(id*2, l, mid, u, v), getvl(id*2+1, mid+1, r, u, v));
}
void solve()
{
     ll n; cin>>n;
     for(int i=1;i<=n;i++)
        cin>>a[i];
     buid(1,1 ,n);
    //  return;
     ll q; cin>>q;
     string s;
     cin.ignore();
     while(q--){
        
        // cout << s << "DEG\n";
        getline(cin,s);
        
        // cout<<s<<"\n";
        // getline(cin, s);
        vector<ll> v,ans;
        v = convert(s);

    // if(v[0]>v[1]) swap(v[0],v[1]);
        v[0]++,v[1]++;
        if(v.size()==3){
            
            if(v[0]<=v[1])  update(1, 1, n, v[0], v[1], v[2]);
            else{
                update(1, 1, n, v[0], n, v[2]);
                update(1, 1, n, 1, v[1], v[2]);
            }
        }else {
            if(v[0]<=v[1])   cout<<getvl(1,1,n, v[0], v[1])<<"\n";
            else{
                
                // cout<<getvl(1, 1, n, v[0], n)<<" "<<getvl(1, 1, n, 1, v[1])<<"a\n";
                cout<<min(getvl(1, 1, n, v[0], n),getvl(1, 1, n, 1, v[1]))<<"\n";
            }
        }
     }


}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //ll tc=1; cin>>tc;
    //for (ll t=1; t<=tc; t++) 
solve();
    return 0;
}