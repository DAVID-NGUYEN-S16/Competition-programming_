/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll INF=30000+7;
const ll MIN=- 1e5+7;
int tree[INF*4], a[INF*4];
struct KQUERY
{
    int i,j, k, vl, id;
};
vector<pair<int,int>>arr(INF);
KQUERY query[200001];
bool cmp1(KQUERY &a, KQUERY &b){
    return a.k<b.k;
}
bool cmp2(KQUERY &a, KQUERY &b){
    return a.id<b.id;
}
void  build(int id,int l, int r){
    if(l>r) return;
    if(l==r) {
        tree[id] = 1;
        return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid );
    build(id*2+1, mid+1, r);
    tree[id] = tree[id*2]+ tree[id*2+1];
}
void update(int id, int l,int r, int u){
    if(u<l || u>r) return;
    if(l==r){
        tree[id]=0;
        return;
    }
    int mid  = (l+r)/2;
    update(id*2, l, mid, u);
    update(id*2+1, mid+1,r, u);
    tree[id] = tree[id*2]+tree[id*2+1];
}
int get(int id, int l, int r, int u, int v){
    if(u>r || v<l) return 0;
    if(l>=u && r<=v) return tree[id];
    int  mid = (l+r)/2;
    return get(id*2, l, mid, u,v)+ get(id*2+1, mid+1, r, u,v);
}
void solve()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i].first;
        arr[i].second = i;
    }
    int q; cin>>q;
    for(int i=1;i<=q;i++){
        cin>>query[i].i>>query[i].j>>query[i].k;
        query[i].id = i;
    }
    build(1,1, n);
    sort(arr.begin()+1, arr.begin()+n+1);
    sort(query+1, query+q+1, cmp1);
    // for(int i=1;i<= n;i++) cout<<arr[i].first<<" ";
    int id = 1;
    for(int i=1;i<=n;i++){
        if(arr[i].first<=query[id].k) update(1, 1, n, arr[i].second);
        else {
            query[id].vl = get(1,1,n,query[id].i, query[id].j);
            id++;
            i--;
        }
        if(id>q) break;
    }
    sort(query+1, query+q+1, cmp2);
    for(int i=1;i<=q;i++) cout<<query[i].vl<<"\n";
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