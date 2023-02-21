#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 1e6 + 6;
struct Q
{
    int u, v, id;
    char types;
    string ans = "N";
    Q(string c, int u, int v, int id){
        types = c;
        u = u;
        v = v;
        id = id;
    }

};
int par[MAX], ranks[MAX];
void init(int u){
    par[u] = u;
    ranks[u] = 1;
}
int get_par(int u){
    if(par[u] == u) return u;
    int p = get_par(u);
    par[u] = p;
    return p;
}
void merger(int a, int b){
    a = get_par(a);
    b = get_par(b);
    if(a!=b){

        if(  ranks[a] < ranks[b]) swap(a, b);
        par[b] = a;
        if( ranks[a] == ranks[b]) ranks[a]++;
    }
}
vector<Q> query[MAX];
void solve()
{
    int n, q, u, v; cin>>n>>q;
    string k;
    int is = 0;
    for(int i = 1; i <= n; i++){
        cin>>k;
        if(k == "C"){
            is++;
            continue;
        }
        if(k == "A") {

            cin>>u>>v;
            query[is].push_back(Q(k, u, v, id));

        }else{
            int id;
            if(k == "Q"){
                cin>>id>>u>>v;
                arr[id].push_back(Q(u, v, i));
            }else {
                cin>> u >>v;
                arr[i].push_back(Q(u,v, i));
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(auto x: connect[i]){
            merge(x.first, x.second);
        }
        for(auto x: query[i]){
            if( get_par(x.))
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
