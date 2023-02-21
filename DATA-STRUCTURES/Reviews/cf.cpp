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
struct ass
{
    int k, x, y, tu, sum = 0;
    // map<pair<int,int>,int>kesach;
    // int ke[1001];

}arr[INF];
bool check[INF];
map<pair<int,int>,int>cpp[INF];
ll kesach[1001][1001];
void solve()
{
   ll n, m, q;
    cin>>n>>m>>q;
    ll k, x, y;
    for(int i=1;i<=q;i++){
        cin>>arr[i].k;
        if(arr[i].k==1|| arr[i].k==2) cin>>arr[i].x>>arr[i].y;
        else {
            cin>>arr[i].tu;
            check[arr[i].tu] = true;
        }
    }
    for(int i=1;i<=q;i++){
        if(arr[i].k==1){
            kesach[arr[i].x][arr[i].y]=1;
            arr[i].sum = arr[i-1].sum+1;
            cout<<arr[i].sum<<"\n";
        }else if(arr[i].k==2){
            arr[i].sum = arr[i-1].sum-kesach[arr[i].x][arr[i].y];
            kesach[arr[i].x][arr[i].y]=0;
            cout<<arr[i].sum<<"\n";
        }else if(arr[i].k==3){
            int s = 0;
            for(int j=1;j<=m;j++){
                kesach[arr[i].tu][j] =  1-kesach[arr[i].tu][j];
                s+=kesach[arr[i].tu][j];
            }
            arr[i].sum = arr[i-1].sum-(m-s)+s;
            cout<<arr[i].sum<<"\n";
        }else{
            arr[i] = arr[arr[i].tu];
            cout<<arr[i].sum<<"\n";
            for(int h=1;h<=n;h++){
                for(int u=1;u<=m;u++) kesach[h][u] = cpp[i][{h, u}];
            }
        }
        if(check[i]==true) {
            for(int h=1;h<=n;h++){
                for(int u=1;u<=m;u++) cpp[i][{h, u}]=kesach[h][u] ;
            }
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