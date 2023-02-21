#include<bits/stdc++.h>
using namespace std;
int tree[10006],n,a[10006];
int ls, rs;
int max_l_r(int id,int l,int r){
    if(ls>r || rs<l ){
        return -100000006;
    }
    if(ls<=l && rs>=r){
        return tree[id];
    }
    int mid = (l+r)/2;
    return max(max_l_r(id*2,l,mid),max_l_r(id*2+1,mid+1,r));
}
void buid_tree(int id,int l,int r){
    if (l==r) {
        tree[id]=a[r];
    }
    int mid = (l+r)/2;
    buid_tree(id*2,l,mid);
    buid_tree(id*2+1,mid+1,r);
    tree[id]=max(tree[id*2],tree[id*2+1]);
}
void solve (){
    cin>>n;
    cin>>ls>>rs;
    for(int i=1;i<=n;i++) cin>>a[i];
    buid_tree(1,1,n);
    cout<<max_l_r(1,1,n);

}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    // int t; cin>>t;
    // while(t--)
    solve();
    return 0;
}