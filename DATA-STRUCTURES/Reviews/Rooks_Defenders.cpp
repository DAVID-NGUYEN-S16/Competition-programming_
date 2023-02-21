/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
#define no cout<<"NO\n"<<endl;
#define yes cout<<"YES\n"<<endl;
const ll MOD=1e9+7;
const ll INF=2e5+7;
const ll MIN=- 1e5+7;
ll n, m;
struct fenwick{
    int bit[INF];
    void update(int id, int vl){
        while(id<=n){
            bit[id]+=vl;
            id += (id&(-id));
        }
    }
    ll getvl(int id){
        int sl = 0;
        while(id>0){
            sl += bit[id];
            id-= (id & (-id));
        }
        return sl;
    }
};
void solve()
{
    cin>>n>>m;
    ll t, x1,y1,x2, y2;
    vector<int>x(n+5), y(n+5);
    fenwick xs, ys;
    while(m--){
        cin>>t;
        if(t==1){
            cin>>x1>>y1;
            if(++x[x1]==1) xs.update(x1, 1);
            if(++y[y1]==1) ys.update(y1, 1);
        }
        if(t==2){
            cin>>x1>>y1;
            if( --x[x1]<=0) xs.update(x1, -1);
            if( --y[y1]<=0) ys.update(y1, -1);
        }
        if(t==3){
            cin>>x1>>y1>>x2>>y2;
            if(xs.getvl(x2) - xs.getvl(x1-1) == x2 - x1+1|| ys.getvl(y2)-ys.getvl(y1-1)== y2-y1+1){
                cout<<"YES\n";
            }else cout<<"NO\n";
       
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
    // ll tc=1; cin>>tc;
    // for (ll t=1; t<=tc; t++) 
solve();
    return 0;
}
