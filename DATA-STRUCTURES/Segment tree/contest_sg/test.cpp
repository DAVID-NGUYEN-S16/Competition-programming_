/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+7;
void solve()
{
    string s[4];
    vector<string>v;
    string t;
    map<char, int>mp,mk;
    for(int i=1;i<=3;i++) {
        cin>>s[i];// x>y
        if(s[i][1]=='>') mp[s[i][0]]++;
        if(s[i][1]=='<') mp[s[i][2]]++;
    }
    mp['A'] +=0;
    mp['B'] +=0;
    mp['C'] +=0;
    set<int> st;
    for(auto x: mp) {
        st.insert(x.second);
        mk[-x.second] =x.first;
    }
    if(st.size()!=3) cout<<"Impossible";
    else {
         for(auto x: mk) cout<<x.second;
    }

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