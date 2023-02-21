/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+7;
int arr[N*4],tree[N*4];
struct query {
    int k,l,r, id,vl;
};

vector<query>v(N*4);
vector<pair<int,int>>p;
bool operator < (const  query& a, const query& b){
    return a.k<b.k;  // săp xếp lại them thứ tự tăng dần của k
}
void build(int id , int l,int r){
    if(l==r){
        tree[id]=1;
        return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1, mid+1,r);
    tree[id] = tree[id*2]+tree[id*2+1]; // cập nhật các giá trị đoạn 
    // cout<<tree[id]<<"a\n";
}
void update(int id, int l, int r, int u){
    if(u<l || u>r) return;
    if(l==r) {
        tree[id]=0;
        // cout<<id<<"id\n";
        return ;
    }
    int mid = (l+r)/2;
    update(id*2,l,mid,u);
    update(id*2+1,mid+1,r,u);
    tree[id] = tree[id*2]+tree[id*2+1];
    // cout<<tree[id]<<"b\n";
}
int get(int id, int l, int r, int u, int v){
    if(l>v || r<u) return 0;
    if(l>=u && r<=v){
        return tree[id];
    }
    int mid = (l+r)/2;
    return get(id*2, l, mid, u,v)+ get(id*2+1, mid+1, r,u,v);
}
bool cmp(const query &a, const query &b){
    return a.id<b.id;
}
void solve()
{
    int n,x; cin>>n;
    p.push_back({0,0});
    for(int i=1;i<=n;i++) {

        cin>>x;
        p.push_back({x,i});

    }
    sort(p.begin(),p.end());
    int que ; cin>>que;
    for(int i=1;i<=que;i++){
        cin>>v[i].l>>v[i].r>>v[i].k;
        v[i].id = i;
    }
    sort(v.begin()+1,v.begin()+que+1);

    build(1,1,n);

    int ids = 1;
    for(int i=1;i<=n;i++){
        if(p[i].first<=v[ids].k){

            update(1,1,n,p[i].second);
        }else{
            v[ids].vl = get(1, 1, n, v[ids].l, v[ids].r);
            cout<<v[ids].vl<<"\n";
            ids++;

            i--;

        }
        // cout<<v[ids].k<<"\n";
        if(ids>que) break;
        // cout<<ids<<" "<<  v[ids].vl<<"\n";
        
    }
    // cout<<ids<<"id\n";
    sort(v.begin()+1, v.begin()+que+1, cmp);
    // for(int i=1;i<=que;i++){
    //     cout<<v[i].vl<<"\n";
    // }

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