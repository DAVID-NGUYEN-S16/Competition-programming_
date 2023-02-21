#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MAX = 1e6 + 7;
const long long MIN =  -1e6;
const long long MOD = 1e9 + 7;
const long long INF = 1e18 + 7;
const long long base = 31;
void solve()
{
    int n; cin>>n;
    string s; cin>> s;
    map<char, char> par1, par_final;
    // cout<<11;
    for(auto x: s){
        // cout<<x;
        if(par_final.count(x)){
            cout<<par_final[x];
        }else {
            for(char c = 'a'; c <= 'z'; c++){
                if(!par1.count(c) && c != x){
                    int cnt = 0;
                    char tmp = x;
                    while(par1.count(tmp)){
                        tmp = par1[tmp];
                        cnt++;
                    }
                    if(tmp == c && cnt != 25) continue;
                
                    par_final[x] = c;
                    par1[c] = x;
                    cout<<c; 
                    break;
                }
            }
        }
    }
    cout<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    #endif
    int t; cin>>t;
    while(t--)
    solve();
    return 0;
}