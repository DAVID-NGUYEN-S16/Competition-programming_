#include<bits/stdc++.h>
using namespace std;
const long long MAX = 5e6+1;
const long long MOD = 1000000003;
const long long base = 31;
long long POW[MAX], hashs[MAX];
long long gethash(long long i,long long j) {
    return (hashs[j] - hashs[i - 1] * POW[j - i + 1] + MOD*MOD) % MOD;
}
void solve(){
    long long n; cin>>n;
    string s; cin>>s;
    s = "#" + s;
    string k = "#aba";
    long long m = 3;
    long long hashk = 0;
    POW[0] = 1;
    for(int i = 1; i <= n; i++) POW[i] = (POW[i-1] * base) %MOD;

    for (int i = 1; i <= 3; i++){
    	hashk = (hashk * base + k[i] - 'a' + 1) ;
    }
    for(int i = 1; i <= n; i++) hashs[i] = (hashs[i-1] * base + s[i] - 'a' + 1) %MOD;

    long long t = 0;
    set<string> mp;
    int l  =0, r = 0 , mas =0, lx = 0, rx=0;
    for(int i = 1; i <= n; i++){
        if(hashk == gethash(i, i + 2)){

                if(t == 1){
                    r = i+2;

                }else {
                    t = 1;
                    l = i; r = i+ 2;
                }
                i++;
        }else {
                if(r - l + 1 >= mas) {
                    lx = l; rx = r;
                    mas = r - l +1;
                }
                r = l = 0;
                t = 0;
        }
    }
    for(int i = lx; i <= rx; i++) cout<<s[i];
/*
14
abaaaaaababbbb
*/

}
int  main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}
