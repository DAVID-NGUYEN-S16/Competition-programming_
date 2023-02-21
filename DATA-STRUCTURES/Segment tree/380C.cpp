#include<bits/stdc++.h>
#define ll long long
const ll N=1e6+5;
using namespace std;
struct Node{
    int opt,open,close;
    Node(){};
    Node(int op, int o, int c) {
        opt=op;
        open=o;
        close=c;
    }
};
Node tree[4*N];
string s;
Node operator+(const Node &left, const Node &right){
    Node res;
    int tmp=min(left.open,right.close);
    res.opt=left.opt+right.opt+tmp;
    res.open=left.open+right.open-tmp;
    res.close=left.close+right.close-tmp;
    return res;
}
void buid(int id,int l,int r){
    if(l==r){
        if(s[l]=='(') tree[id]=Node(0,1,0);
        else tree[id]=Node(0,0,1);
        return ;
    }
    int mid=(l+r)/2;
    buid(id*2,l,mid);
    buid(id*2+1,mid+1,r);
    tree[id]=tree[id*2]+tree[id*2+1];
}
Node getvalue(int id, int ls, int rs, int l,int r ){
    if(ls>r ||rs<l){
        return Node(0,0,0);
    }
    if(l<=ls && r<=rs) return tree[id];
    int mid=(l+r)/2;
    return getvalue(id*2,ls,rs,l,mid)+getvalue(id*2+1,ls,rs,mid+1,r);
}
int main(){
    string h;
    cin>>h;
    int t; cin>>t;
    int n=h.size();
    s="a"+h;
    cout<<s<<endl;
    int l,r;
    buid(1,1,n);
    for(int i=0;i<t;i++){
        cin>>l>>r;
        cout<<getvalue(1,l,r,1,n).opt*2<<"\n";
    }
    return 0;
}