#include<bits/stdc++.h>
using namespace std;
int par[50], ranks[50];
void make_set(int u){
    par[u] = u;
    ranks[u] = 1;
}
int find_set(int u){
    if(par[u] == u) return u;
    int p = find_set(par[u]);
    par[u] = p;
    return p;
}
void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if( ranks[a] < ranks[b]) swap(a, b);
        par[b] = a;
        if( ranks[a] == ranks[b]) ranks[a]++;
    }
}
void solve(){
    for(int i = 0; i <= 26; i++) make_set(i);
    int n; cin>>n;
    string s;
    int cnt = 0;
    set<int>letter;
    vector<int> v(28);
    for(int i = 1; i <= n; i++){
        cin>>s;
        int pars_tmp = s[0] - 'a';
        vector<int>st;
        for(auto x: s){
                v[x-'a'] = 1;
            if(find_set(x - 'a') != (x - 'a')){
                pars_tmp = x- 'a';
                st.push_back(x-'a');
            }else st.push_back(x-'a');
        }
        for(auto x: st) {
                union_set(x, pars_tmp);
        }
    }
    for(int i = 0; i <= 26; i++){
        if(v[i] == 1){ letter.insert(find_set(i));
        //cout<<i<<" "<<find_set(i)<<endl;
        }
    }
    cout<<letter.size();
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
