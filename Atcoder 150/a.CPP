#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 1e6 + 7;
void solve()
{

    int n, k ; cin>>n>>k;
    string s;
    cin>>s;
    int cnt1 = 0, lt = 0, have = 0;
    bool check = false;
    // TH1
    for(int i = 0; i < n ; i++){
        if(lt >= k) check = true;
        if(s[i] == '1' && i < n -k ) cnt1++, lt++;
        else if(i < n- k) lt=  0;
        if(s[i] == '?') have = 1;
    }
    if(check == true && have == 1 && cnt1 <= k || ){
        cout
    }
    for(int i = 0; i < n; i++){
        if
        if(s[i] == '1'){
            cnt++;
        }else cnt1 = 0;
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    int t; cin>>t;
    while(t--)
    solve();
}
