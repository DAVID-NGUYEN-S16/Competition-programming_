/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e9+7;
const ll INF=1e5+7;
const ll MIN=- 1e5+7;
void solve()
{
    int n,x,y; cin>>n;
    // vector<pair<int, int>>v;
    map<int,int>l, r;
    int cnt = 0;
    map<pair<int,int>, int>mp;
    int cnts[n+5];
    cnts[1]=0;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        // v.push_back({x,y});
        // mp[{x,y}]=i;
        // if(mp[{x,y}]!=0) {
        //     cnt += l[x]+;[i]
        //     // cnt+= l[x]+r[y];
        //     // cout<<x<<" "<<y<<"\n";
        // }
        cnts[i]=l[x]+r[y];
        cnt+=cnts[i];
        if(mp[{x,y}]!=0) {
            cout<<cnt<<"\n";
            cnt-=cnts[mp[{x,y}]];
            cout<<mp[{x,y}]<<" "<<i<<"\n";
            // cout<<x<<" "<<y<<"\n";
            mp[{x,y}]=i;
        }else mp[{x,y}]=i;
        // if(x==1 && y==5) cout<<mp[{x,y}]<<"\n";
        l[x]++;
        r[y]++;

    }
    cout<<cnt<<"\n";
}

/*

cout --> ostream
cin -->> istream

10
5 1 6 2 8 3 4 10 9 7

a =

*/

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