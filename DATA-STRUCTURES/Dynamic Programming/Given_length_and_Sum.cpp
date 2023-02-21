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
void pri(){
    cout<<"-1 -1";
}
void solve()
{
    int m, s; cin>>m>>s;
    vector<int>mins, mas;
    int res = 0;
    if(s==0 && m!=1){
        pri();
        return;
    }
    for(int i=0;i<m;i++){
        res = min(9, s);
        mins.push_back(res);
        mas.push_back(res);
        s -= res;
    }
    if(s>0){
        // c
        pri();
        return;
    }
    if(mins[m-1]==0 && m!=1){
        mins[m-1] = 1;
        for(int i=m-2;i>=0;i--) if(mins[i]>0) {mins[i]--;break;}
    }
    for(int i=m-1;i>=0;i--) cout<<mins[i];cout<<" ";
    if(mas[0]==0&& m!=1){
        mas[0]=1;
        for(int i=1;i<m;i++) if(mas[i]>0) {mas[i]--; break;}
    }
    for(auto x: mas) cout<<x;
    
    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    //ll tc=1; cin>>tc;
    //for (ll t=1; t<=tc; t++) 
solve();
    return 0;
}