#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 1e6 + 7;
const ll INF = 1e18 + 7;
const ll MOD = 1e9 + 7;
void solve()
{
    int n, k; cin>>n>>k;
    string s; cin>>s;
    s = '#' + s;
    int j = n - k;
    for(int i = k + 1; i <= (n+1)/2; i++){
            if(s[i] != s[j]){
                cout<<"No\n"; return;
            }
            j--;
    }
    map<char, int> cnt;
    for(int i = 1; i <= k; i++) cnt[s[i]]++;
    j = n;
    for(int i = 1; i <= k; i++){
        cnt[s[j]]--;
        if(cnt[s[j]] < 0) {
            cout<<"No\n"; return;
        }
        s[i] = s[j];
        j--;
    }
    s.erase(s.begin());
    cout<<"Yes\n";
    cout<<s<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin>>t;
    while(t--)
    solve();
    return 0;
}

