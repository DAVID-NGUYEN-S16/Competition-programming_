#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 1e6 + 7;
int par[MAX], ranks[MAX];
void init(int u){
    par[u] = u;
    ranks[u] = 1;
}
int find_set(int u){
    if(par[u] == u )return u;
    int p = find_set(par[u]);
    par[u] = p;
    return p;
}
void make_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){

        if(ranks[a] < ranks[b]) swap(a, b);
        par[b] = a;
        if(ranks[a] == ranks[b]) ranks[a]++;
    }
}
void solve()
{
    int n, k; cin>>n>>k;
    string s; cin>>s;
    s = "#" + s;
    for(int i = 1; i <= n; i++) init(i);
    for(int i = 1; i <= n; i++){

        if(i + k <=n ) make_set(i, i +k);
        if((n+1)/2 >= i) make_set(i, n-i+1);
    }
    map<int, vector<int>> v;
    for(int i = 1; i <= n; i++){
        v[find_set(i)].push_back(i);
    }
    int ans = 0;
    for(int i = 1; i <= (n+1)/2; i++){
        if(v[i].size() == 1){
            if(s[i] != s[n-i+1]) ans++;
            cout<<s[i]<<" "<<s[n-i+1]<<endl;
        }
    }
//    cout<<ans<<endl;
    for(auto x: v){
        vector<int> cnt(28);
        int mas = 0;
        for(int y: x.second){
            cnt[s[y] - 'a'] ++;
            mas = max(mas, cnt[s[y] - 'a']);
        }
        ans+= (x.second.size() - mas);
//        cout<<mas<<" "<<cnt[mas]<<endl;
//        for(int y: x.second) cout<<cnt[s[y]- 'a']<<" ";
//        cout<<endl;
//        cout<<x.second.size() <<" "<< cnt[mas]<<endl;
//        cout<<x.first <<" "<<x.second.size()<<endl;
    }
    cout<<ans<<"\n";

}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    int t; cin>>t;
    while(t--)
    solve();
}
