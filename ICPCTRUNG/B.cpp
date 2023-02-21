#include<bits/stdc++.h>
using namespace std;
const long long MAX = 1e6+7;
vector< int> z(MAX);
map<int, int> mp;
vector<int> lengths;
string s ;
void zfunction(){

    int n = s.size();
    int t  =0 ;
    for(int i = 1, r = 0, l  =0; i < n; i++){
        if(i <= r) z[i] = min(r - i + 1, z[i- l]);
        while(z[i] + i  < n && s[z[i]] == s[z[i]+i]) ++z[i];
        if(z[i] +  i -1 > r) l = i, r = z[i] + i -1;
    }

    for(int i = 1; i< n; i++){
        lengths.push_back(z[i]);
    }
    sort(lengths.begin(), lengths.end());
}
void solve(){
    int n; cin>>n;
    int sz = s.size() - n;
    int id = lower_bound(lengths.begin(), lengths.end(), n) - lengths.begin();
    if(z[sz] == n){
            if(lengths.size() - id >=2) cout<<"YES"<<" "<<1 + lengths.size() - id<<"\n";
            else cout<<"NO\n";
    }else cout<<"NO\n";
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>s;
    zfunction();
    int t; cin>>t;
    for(int i = 1; i<=t; i++){
         solve();
    }


}
