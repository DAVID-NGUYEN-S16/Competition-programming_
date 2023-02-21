/* ---While (I <= you) I++;---*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define what_is(x) cerr << #x << " is " << x << endl;
#define cint int t; cin >> t; while(t--)
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll N = 1e5 + 9, MOD = 1e9 + 7;
void solve() {
    string s;
    int n, ans = 1e9, today, cur, tmp, thu, ngaydu;
    cin >> s >> n;
    int a[n+1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<string,int> mp;
    mp["Mon"] = 2;
    mp["Tue"] = 3;
    mp["Wed"] = 4;
    mp["Thu"] = 5;  
    mp["Fri"] = 6;
    mp["Sat"] = 7;
    mp["Sun"] = 8;
    for (int i = 0; i < n; i++) {
        thu = mp[s] - a[i]%7;
        while (thu <= 1) thu += 6;
        if (a[i] >= 30) {
            tmp = a[i]/30;
            ngaydu = a[i] - tmp*30;
            thu += tmp*2;
        }
        else ngaydu = a[i];
        if (thu > 8) thu = thu%8 + 1;
        cur = 30;
        if (thu==5) {
            cur+=2;
        }
        else if (thu==6) cur++;
        ans = min(ans, cur - ngaydu);
    }
    cout << ans << endl;
}
int main () {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios 
    solve();
    return 0;
}