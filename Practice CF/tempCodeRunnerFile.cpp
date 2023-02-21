#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e9+7;
const ll INF=1e5+7;
const ll MIN=- 1e5+7;
void solve()
{
    string s; cin>>s;
    for(int i = 0; i<s.size(); i++){
        if(s[i] == '.'){
            int x = s[i+1] - '0';
            if(x<5) {
                cout<<s.substr(0, i)<<"\n";
                return;
            }else{
                if(s[i-1] == '9') {
                    cout<<"GOTO Vasilisa.";
                    return;
                }
                int y =1 + ( s[i-1] - '0');
                s[i-1] = (y + '0');
                cout<<s.substr(0,i)<<"\n";
                return;

            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //ll tc=1; cin>>tc;
    //for (ll t=1; t<=tc; t++) 
    solve();
    return 0;
}