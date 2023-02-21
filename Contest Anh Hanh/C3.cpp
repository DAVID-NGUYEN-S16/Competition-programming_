
#include<bits/stdc++.h>
using namespace std;

const long long MAX = 1e6 + 7;
const long long base = 31;
const long long MOD = 1e9 + 7;
long long POW[MAX], hashs[MAX];
vector<long long > zfunciton(string s){
    long long n=s.size();
    vector<long long> z(n+5);
    for (long long i=1, l=0, r=0; i<n; i++)
    {
        if (i<=r) z[i]=min(z[i-l], r-i+1);
        while (i+z[i]<n && s[z[i]]==s[i+z[i]]) ++z[i];
        if (i+z[i]-1>r) l=i, r=i+z[i]-1;
    }
    return z;
}
long long sokhop( string a, string b){
    vector<long long> ans = zfunciton(a + "#" + b);
    for(int i = 0; i  < ans.size(); i++)
        if(ans[i] == a.size()) return i;
    return -1;

}
void solve()
{
    string a, b;
    while(cin>>a>>b){
    int ida = MAX, idb =MAX , cntb1 = 0, cntb2 = 0;
    for(int i = 0; i < b.size(); i++){
        if(ida == MAX && b[i] == 'A') ida = i;
        if(idb == MAX && b[i] == 'B') idb = i;
        if(b[i] == 'B') cntb1++;
    }
    for(int i = 0; i < a.size(); i++) if(a[i] == 'B') cntb2++;

    if(ida < idb || a.size() > b.size()){
        cout<<"No\n";
    }else {
        int inv = 0;
        if(cntb1 > cntb2)  {
            if((cntb1 - cntb2) %2 !=0) {
                    inv  = 1;
                    reverse(a.begin(), a.end());
            }
        }
        long long id =  sokhop(a, b);
        if(inv == 0 && id >=0){
            cout<<"Yes\n";
        }else {
            long long ch = 0;
//            cout<<id - a.size()<<" "<<id<<endl;
            for(int i = 0; i < id - a.size()-1 && i < b.size(); i++){
                if(b[i] == 'B' && id >= 0){
                    cout<<"Yes\n";
                    ch = 1;
                    break;
                }
            }
            if(ch == 0 || id < 0) cout<<"No\n";
        }
    }
    }


}
int main()
{

    ios_base::sync_with_stdio(false); cin.tie(NULL);
     freopen("abba.inp", "r", stdin);
    freopen("abba.out", "w", stdout);
    solve();
}

