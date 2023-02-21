#include<bits/stdc++.h>
using namespace std;
vector<int> zfuntion(string a){
    vector<int> z(100);
    for(int i = 1, l = 0 , r = 0; i < a.size(); i++){
        if(i <= r) z[i] = min(r - i + 1, i - l);
        while(i + z[i] < a.size() && a[z[i]] == a[i+ z[i]]) z[i]++;
        if(i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    for(int i = 0; i < a.size(); i++){
        cout<<i<< ": "<<z[i]<<endl;
    }
}
void solve(){
    zfuntion("aaabaab");
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
