#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int n,a[100001], tree[100002];
void buid_tree(int id,int l,int r){
    if(l==r) {
        tree[id]=a[r];
        return;
    }
    int mid = (l+r)/2;
    buid_tree(id*2,l,mid);
    buid_tree(id*2+1,mid+1,r);
    tree[id]=max(tree[id*2],tree[id*2+1]);
}
void solve (){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    buid_tree(1,1,n);
    cout<<tree[1];
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