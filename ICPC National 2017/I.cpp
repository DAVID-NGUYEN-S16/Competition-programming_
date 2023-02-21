#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 1e6 + 7;
void solve()
{
    int n; cin>>n;
    vector<string> ans;
    int p = 0,  po= 0;
    // so luong 0 = 1 or ko co 2 so 0 lien lien
    for(int i = 0 ; i < (1<<n); i++){
        string s = "";
        int  cnt = 0;
        bool check = true;
        for(int j = 0; j < n; j++){
            if(i&(1<<j)){
                s = "1"+s;
                cnt++;
            }else {
                if(s[0] == '0') check = false;
                s = "0"+s;
            }
        }
        if(cnt == n-cnt || check) {
                p++;
                cout<<s<<endl;
        }




    }
    cout<<p<<endl;

}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin>>t;
    while(t--)
    solve();
    return 0;
}
