#include<bits/stdc++.h>
using namespace std;
void solve(){
    int t; cin>>t;
    string s; cin>>s;
    int n = s.size();
    if(s[0] == 'A' && s[n-1] == 'B' ||  s == "AB" || s == "BA"){
        cout<<"No"<<endl; return;
    }

    cout<<"Yes"<<endl;;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
//    int t; cin>>t;
//    while(t--)
    solve();
    return 0;
}
