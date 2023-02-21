#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int ans = 0;
int n, m;
string s, t;
vector<int> v1, v2;
int Ckn(int k, int n) {
    if (k > n) return 0;
    int tu = 1;
    int mau = 1;
    for (int i = n-k+1; i <= n; i++) {
        tu *= i;
    }
    for (int i = 2; i <= k; i++) {
        mau *= i;
    }
    return tu/mau % mod;
}
void xuli(string &s, string t) {
    vector<bool> vs(26,0);
    string tmp = "";
    for (int i = 0; i < t.size(); i++) {
        vs[t[i] - 'a'] = 1;
    }
    for (int i = 0; i < s.size(); i++) {
        if (('a' <= s[i] && s[i] <= 'z' ) && vs[s[i] - 'a']) {
            tmp += s[i];
            i++;
            while ('0' <= s[i] && s[i] <= '9') {
                tmp += s[i];
                i++;
            }
            i--;
        }
    }
    s = tmp;
}
void xuli2(string &s, vector<int> &v) {
    string tmp = "";
    int k = 0;
    for (int i = 0; i < s.size(); i++) {
        if ('a' <= s[i] && s[i] <= 'z') {
            tmp += s[i];
            i++;
            k = 0;
            while ('0' <= s[i] && s[i] <= '9') {
                k = k * 10 + (int)(s[i] - '0');
                i++;
            } 
            i--;
            v.push_back(k);
        }
    }
    s = tmp;
}
void xuli3(string &s, vector<int> &v) {
    int cnt ;
    string tmp = "";
    for (int i = 0; i < s.size(); i++) {
        cnt = 1;
        int j = i+1;
        while (j < s.size() && s[j]==s[i]) cnt++, j++;
        v.push_back(cnt);
        tmp += s[i];
        i = j-1;
    }
    s = tmp;
}

void backtrack(int u, int v, int cnt) {
    if (v == t.size()) {
        ans += cnt;
        return;
    }
    if (u == s.size()) {
        return;
    }
    for (int i = u; i < s.size(); i++) {
        if (s[i] == t[v]) {
            if (v2[v] > 1) {
                ans += Ckn(v2[v], v1[i]);
                backtrack(i+1, v+1, cnt*v1[i]);
            }
        }
    }
}

void solve() {
    
    cin >> n >> m >> s >> t;
    xuli(s, t);
    xuli2(s, v1);
    xuli3(t, v2);
    backtrack(0, 0, 1);
    cout << ans << endl;
}

signed main() {
    freopen("PASSWORD.INP", "r", stdin);
    freopen("PASSWORD.OUT", "w", stdout);
    solve();
    return 0;
}