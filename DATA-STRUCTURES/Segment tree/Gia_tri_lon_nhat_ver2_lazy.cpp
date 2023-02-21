/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+7;
int lazy[N*4], tree[N*4];
void update(int id, int l, int r, int u, int v, int x){
     if(lazy[id]!=0) { // cập  nhật giá trị của tree nếu lazy != 0
        tree[id] += lazy[id];
        if(l!=r){
            lazy[id*2] += lazy[id];
            lazy[id*2+1] += lazy[id];
        }
        lazy[id] = 0 ;
    }
    if(l>v || r < u) return ; // nếu nằm ngoài vùng thì dừng 
    if(u<=l && v>=r){   
        tree[id] += x;  // nếu l r nằm ở phía trong thì ra cập nhập giá trị của tree
        if(l!=r){       // +x và đẩy xuống 2 con phía dưới 
            lazy[id*2] += x;
            lazy[id*2+1] +=x;
        }
        lazy[id] = 0 ; // chú ý phải cho lazy[id] =0 vì nếu không sẽ bị cộng nhiều lần
        return;  // dừng lại ta chỉ xét nút cha 
    }
    int mid = (l+r)/2;
    update(id*2, l, mid, u,v,x); // truy vấn 2 bên
    update(id*2+1, mid +1, r, u,v,x);
    tree[id] = max(tree[id*2], tree[id*2+1]); // cập nhật giá trị max
}
int get_query(int id, int l, int r, int u, int v){
    if(lazy[id]!=0){
        tree[id]+= lazy[id];
        if(l!=r){
            lazy[id*2] += lazy[id];
            lazy[id*2+1] += lazy[id];
        }
        lazy[id] = 0;
    }
    if(l>v || r<u) return -N;
    if( l >= u && r <= v){
        return tree[id];
    }
    int mid = (l+r)/2;
    return max(get_query(id*2, l, mid, u, v), get_query(id*2+1,mid+1,r, u, v));
}
void solve()
{
    int n, m, a,b,c,d; cin>>n>>m;
    while(m--){
        cin>>a;
        if(a==0){
            cin>>b>>c>>d;
            update(1,1,n,b,c,d);
        }else{
            cin>>b>>c;
            cout<<get_query(1, 1, n, b, c)<<"\n";
        }

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