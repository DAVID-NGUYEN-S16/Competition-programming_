#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define x first
#define y second

ll MOD = 1e9+7;
const int MAX = 1000005;
string a, b;
int lena, lenb;

bool check(int vt){
    for(int i=0; i<lena; i++){
        if(vt + i >= lenb)
            return false;
        if(a[i] != b[vt+i])
            return false;
    }
    return true;
}

int main(){

    // freopen("in.txt", "r", stdin);
    freopen("abba.inp", "r", stdin);
    freopen("abba.out", "w", stdout);
    int t = 3;
    while(t--){
        cin>>a>>b;
        lena = a.size(); lenb = b.size();
        vector<int> f(1005, 0);
        for(int i=0; i<lenb; i++){
            f[i] = (b[i] == 'B');
            if(i)
                f[i] += f[i-1];
        }
        bool ans = false;
        for(int i=0; i<lenb; i++){
            if(check(i)){
                if(i && b[0] == 'A')continue;
                int l = 0;  if(i) l = f[i-1];
                int r = f[lenb - 1] - f[i+lena-1];
                if(l == r) ans = true;
            }
        }
        reverse(a.begin(), a.end());
        for(int i=0; i<lenb; i++){
            if(check(i)){
                if(i && b[0] == 'A')continue;
                int l = 0;  if(i) l = f[i-1];
                int r = f[lenb - 1] - f[i+lena-1];
                if(l == r + 1) ans = true;
            }
        }
        cout<<(ans ? "Yes\n" : "No\n");
    }
    return 0;
}


//#include<bits/stdc++.h>
//using namespace std;
//const long long MAX = 1e5 + 7;
//const long long base = 31;
//const long long MOD = 1e9 + 7;
//long long POW[MAX], hashs[MAX];
//long long gethash(long long i, long long j){
//    return (hashs[j] - hashs[i-1] * POW[j - i + 1] + MOD*MOD) %MOD;
//}
//bool check(string s){
//    long long id = (s.size() + 1) /2;
//    long long j = s.size()-1;
//    for(int i = 0; i < id; i++){
//        if(s[i] != s[j]) return false;
//        j--;
//    }
//    return true;
//}
//void solve()
//{
//    string a, b;
//    cin>>a>>b;
//    if(check(a) == false || a.size() > b.size() || check(b) == true){
//        cout<<"NO\n";
//        return;
//    }
//    long long szb  = b.size(), sza = a.size();
//    a = "#" + a;
//    b = "#" + b;
//    POW[0] = 1;
//    for(int i = 1; i <= szb; i++) POW[i] = (POW[i-1] * base) % MOD;
//    // hash a
//    long long hasha = 0;
//    for(int i = 1; i <= sza; i++) hasha = (hasha* base + a[i] - 'A' + 1) %MOD;
//    for(int i = 1; i <= szb; i++)
//        hashs[i] = (hashs[i-1] * base + b[i] - 'A' + 1) %MOD;
//    for(int i = 1; i + sza -1 <= szb; i++){
//        if(hasha == gethash(i, i + sza -1)){
//            cout<<"Yes\n";
//            return;
//        }
//    }
//    cout<<"No\n";
//
//}
//int main()
//{
//
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
//    solve();
//}
