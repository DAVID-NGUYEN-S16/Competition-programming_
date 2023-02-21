/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
ll MOD=1e9+7;
const ll INF=2e5+7;
const ll MIN=- 1e5+7;
struct Matrix{
    ll res[3][3];
    void assign(){
        res[1][1] = 0;
        res[1][2] = 0;
        res[2][1] = 0;
        res[2][2] = 0;
    }

}tree[INF*4], arr[INF];
Matrix I;

Matrix operator *(Matrix a, Matrix b){
    Matrix ans;
    ans.assign();
    for(ll i=1;i<=2;i++){
        for(ll j=1;j<=2;j++){
            for(ll k=1;k<=2;k++){
                ans.res[i][j] += a.res[i][k]*b.res[k][j];
            }
            ans.res[i][j]%=MOD;
        }
    }
    return ans;
}
void update(ll id, ll l, ll r){
    if(l>r) return ;
    if(l==r){
        tree[id] = arr[l];
        
        return;
    }
    ll mid = (l+r)/2;
    update(id*2+1, l, mid);
    update(id*2+2, mid+1, r);
    tree[id] = tree[id*2+1] * tree[id*2+2];
    // cout<<id<<"\n";
    // for(ll i=1;i<=2;i++){
    //         for(ll j=1;j<=2;j++) cout<<tree[id].res[i][j]<<" ";
    //         cout<<"\n";
    // }
    // cout<<"\n";
}
Matrix getvl(ll id, ll l, ll r, ll lx, ll rx){
    if(l>rx || r<lx) return I;
    if(l>=lx && r<=rx) return tree[id];
    // cout<<l<<" "<<r<<"\n";
    ll  mid = (l+r)/2;
    Matrix a = getvl(id*2+2, mid+1, r, lx, rx), b = getvl(id*2+1, l, mid, lx, rx);
    return b*a;
}
void solve()
{
    ll r, n, q; cin>>r>>n>>q;
    MOD = r;
    I.assign();
    I.res[1][1] = 1;
    I.res[2][2] = 1;

    for(ll i=1;i<=n;i++){
        arr[i].assign();
        for(ll j=1;j<=2;j++){
        for(ll k=1;k<=2;k++) cin>>arr[i].res[j][k];
        }
    }
    // cout<<MOD<<"\n";
    // Matrix ans = arr[2]* arr[3];

    // for(int k=1;k<=n;k++){
        // for(int i=1;i<=2;i++){
        //     for(int j=1;j<=2;j++) cout<<ans.res[i][j]<<" ";
        //     cout<<"\n";
        // }
    //     cout<<"\n";
    // }
    update(1, 1, n);
    while(q--){
        int u, v;
        cin>>u>>v;
        Matrix ans = getvl(1, 1, n, u, v);
        for(int i=1;i<=2;i++){
            for(int j=1;j<=2;j++) cout<<ans.res[i][j]<<" ";
            cout<<"\n";
        }
        cout<<"\n";
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