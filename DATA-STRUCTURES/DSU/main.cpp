#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 1e6 + 7;
int par[MAX], sz[MAX];
void make_set(int v){
    par[v] = v;
    sz[v] = 1;
}
int find_set(int u){
    if(par[u] == u) return u;
    int p =  find_set(par[u]);
    par[u] = p;
    return p;
}
void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if( a != b){
        if(sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        if(sz[a] ==  sz[b]) sz[a]++;
    }
}
void solve()
{
    for(int i = 1; i <= 10; i++) make_set(i);
    union_set(1, 2);
    union_set(4, 3);
    union_set(1, 4);
    union_set(5, 6);
    if(find_set(5) == find_set(2)) cout<<"YES\n";
    else cout<<"NO\n";

}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie();
    solve();
}
