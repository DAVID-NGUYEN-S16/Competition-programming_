/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll INF=3e5+7;
const ll MIN=- 1e5+7;
int arr[INF*4], check[INF*4];
void seg(int id, int l,int r, int u, int v, int vl){
    if(l>v || r<u||check[id]==1) return ;
    if(l==r){
        if(l!=vl){
            check[id]=1;
            arr[l]=vl;
        }
        return;
    }
    int mid = (l+r)/2;
    seg(id*2, l, mid, u, v, vl);
    seg(id*2+1, mid+1, r, u, v, vl);
    if(check[id*2]==1 && check[id*2+1]==1) check[id]=1;
    else check[id]=0;
    
}
void solve()
{
    int n,q; cin>>n>> q;
    int l, r, x;
    for(int i=1;i<=n;i++) {
        cin>>l>>r>>x;
        seg(1,1, n, l, r,x);
    }
    for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
    


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