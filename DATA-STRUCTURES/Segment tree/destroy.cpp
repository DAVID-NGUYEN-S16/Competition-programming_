/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll INF=1e5+7;
const ll MIN=- 1e5+7;
ll arr[INF], parent[INF],sum[INF],  sz[INF], pos[INF], ans, sss[INF];
bool check[INF];
void make_set(ll id){
    parent[id]=id;
    sum[id] = arr[id];
    sz[id]=1;
}
ll find_set(ll id){
    if(id ==  parent[id]) return id;
    ll p = find_set(parent[id]);
    parent[id] = p;
    return p;
}
void join_sub(ll a,ll b){
    a = find_set(a);
    b = find_set(b);
    // cout<<a<<" "<<b<<"\n";
    if(a!=b){
        if(a<b) swap(a,b);
        parent[b]=a;
        sz[a]+=sz[b];
        sum[a]+=sum[b];
        // cout<<sum[a]<<" "<<sum[b]<<" "<<a<<"\n";
    }
}
void solve()
{
    ll n; cin>>n;
    for(ll i =1; i<=n;i++) cin>>arr[i];
    for(ll i=1;i<=n;i++) {
        cin>>pos[i];
        make_set(i);
    }
    // chú ý rẳng vì đề bải chắc chắn sẽ phá hủy hết, nên chúng ta quay ngược lại hồi sinh 1 phần tử cuối tịnh tiến đến cuối cùng, nhớ rằng số cuối cùng bằng 0;
    for(ll i=n;i>=1;i--){
        check[pos[i]] = true;
        if(pos[i]>1 && check[pos[i]-1]){
            join_sub(pos[i], pos[i]-1);
            // c
        } 
        if(pos[i]<n && check[pos[i]+1]) join_sub(pos[i], pos[i]+1);
        ans = max(ans, sum[find_set(pos[i])]);
        // cout<<sum[find_set(pos[i])]<<"\n";
        /* tại sao phải lấy ans củ, vì khi mồi sinh thì vẫn còn các cụm tách rời mà lúc trc chúng ta lấy, nhưng vì mỗi lần max nên lúc nào cũng giữ đc giá trị lớn nhất*/
        sss[i-1] = ans;
    }
    // sss[1]=0;
    for(ll i=1;i<=n;i++) cout<<sss[i]<<"\n";
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