/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll MOD= 1e9+7;
const ll INF=1e6+7;
const ll MIN=- 1e5+7;
struct Trie{
    bool last;
    Trie *n[26];
};
Trie container[800000];
ll ncon;
ll n, N;
string a, tmp;
Trie root;
ll f[INF];
void add(string b){
    Trie *p = &root;
    for(ll i=0;b[i]!=0;i++){
        ll t = b[i] - 'a';
        if(p->n[t]!=NULL) p = p->n[t];
        else{
            p->n[t] = container + ++ncon;
            // cout<<container->n[t]<<"\n";
            p = p->n[t];
            // cout<<p->n[t]<<"\n";
        }
    }
    p->last = true;
}
ll searchvl(){
    for(ll i=n-1;i>=0;i--){
        Trie *p = &root;
        for(ll j = i;j<n;j++){
            ll t = a[j] - 'a';
            if(p->n[t]==NULL) break;;
            p = p->n[t];
            if(p->last) f[i] +=f[j+1];
 
        }
        f[i]%=MOD;
    }
    return f[0];
}
void solve()
{
    cin>>a;
    cin>>N;
    n = a.size();
    char a;
    string b;
    for(ll i=0;i<N;i++){
        cin>>a>>b;
        cin>>tmp;
        add(tmp);
    }
    f[n] = 1;
    cout<<searchvl()<<"\n";
 
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