#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll base = 31;
const ll MAX = 1e6 + 7;
const ll MOD = 1e9 + 7;
ll par[MAX], ranks[MAX];
void make_set(int u){
    par[u] = u;
    ranks[u] = 1;
}
ll find_par(int u){
    if(par[u] ==  u) return u;
    int p = find_par(par[u]);
    par[u] = p;
    return p;
}
void join_set(int a, int b){
    a = find_par(a);
    b = find_par(b);
    if(a != b){
        if(ranks[a] < ranks[b]) swap(a, b);
        par[b] = a;
        if(ranks[a] == ranks[b]) ranks[a]++;
    }
}
void solve(){
    for(int i = 1; i <= 100; i++) make_set(i);
    join_set(1, 2);
    join_set(2, 3);
    cout<<find_par(1) <<" "<<find_par(2);

}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
