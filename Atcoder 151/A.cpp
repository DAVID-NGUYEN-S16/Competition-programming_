#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n; cin>>n;
    string a, b; cin>>a>>b;
    int cnta = 0, cntb  =0;
    for(auto x: a) if(x == '1') cnta++;
    for(auto x: b) if(x == '1') cntb++;
    if(cnta > cntb) swap(a , b);
    vector<char> ans(n+5, '0');
    for(int i = n-1; i >=0; i--){
        if(cnta == cntb){
            break;
        }
        if(a[i] == b[i]) continue;
        char x = b[i];
        cnta++;
        if(x == '1') cntb --;
        ans[i] = x;

    }
    if(cnta !=  cntb){
        cout<<-1; return;
    }
    for(int i = 0; i < n; i++) cout<<ans[i];

}
 int main()
 {

     ios_base::sync_with_stdio(false); cin.tie(NULL);
     cout.tie(NULL);
     solve();
     return 0;
 }
