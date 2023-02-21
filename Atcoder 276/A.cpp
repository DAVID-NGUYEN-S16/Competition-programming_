#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long MAX = 1e6 + 7;
const long long INF = 1e18 + 7;
const long long MOD = 1e9 + 7;
void solve()
{
    string s; cin>>s;
    int id = -1;
    for(int i  = 0; i< s.size(); i++){
        if(s[i] == 'a') id = i+1;
    }
    cout<<id;
}
int main()
{

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
