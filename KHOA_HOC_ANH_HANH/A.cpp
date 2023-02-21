#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e9+7;
const ll INF=1e5+7;
const ll MIN=- 1e5+7;
void solve()
{
    string s1, s2; cin>>s1>> s2;
    // if(s1 == "Violet") s1 = "Violet";
    // if(s2 == "Violet") s2 ="Violet";
    string arr[6] = {"Yellow", "Green", "Blue", "Violet", "Red", "Orange"};
    map<pair<string, string>, int> mp;
    map<string, int> pos;
    mp[{"Red", "Green"}]  =1;
    mp[{"Orange", "Blue"}]  =1;
    mp[{"Yellow", "Violet"}]  =1;
    for(int i = 0; i<6; i++) pos[arr[i]] = i;
    if(s1== s2){
        cout<<"Same";
    }else if(mp[{s1, s2}] ==1 || mp[{s2, s1}]==1) cout<<"Complementary";
    else {
        if(abs(pos[s1] - pos[s2]) ==1 || pos[s1] == 0 && pos[s2] == 5 || pos[s1] == 5 && pos[s2] == 0) cout <<"Adjacent";
        else {
            // cout<<pos[s1]<<" "<<pos[s2]<<"\n";
            if(pos[s1] == 5 && pos[s2] == 1 || pos[s2] == 5 && pos[s1] == 1 ) cout<<arr[0];
            else if(pos[s1] == 4 && pos[s2] == 0 || pos[s2] == 4 && pos[s1] == 0 ) cout<<arr[5];
            else if(abs(pos[s1] - pos[s2]) == 2) cout<<arr[abs(pos[s1] + pos[s2])/2];
            else cout<<"None";
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    freopen("color.inp", "r", stdin);
    freopen("color.out", "w", stdout);
    // #endif
    //  #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    //ll tc=1; cin>>tc;
    //for (ll t=1; t<=tc; t++) 
    solve();
    return 0;
}