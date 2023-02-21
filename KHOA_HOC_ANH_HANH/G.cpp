#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e18+7;
const ll INF=1e18+7;
const ll MIN=- 1e5+7;
const ll MAX= 10000000;
// Solution 
/* Nếu có 3 số 10 thì chỉ cần lấy 2 số thôi*/
pair<int, int> pos[MAX+5];
int arr[MAX+5];
void solve()
{
    int n; cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>arr[i];
        if(pos[arr[i]].first ==0) pos[arr[i]].first = i;
        else pos[arr[i]].second = i;
    }
    long long res = INF;
    pair<int,int> best;
    for(int  i = 1; i<=MAX; i++){
        int k = 0, h = 0;
        for(int j = i; j<=MAX; j+=i){
            int u = pos[j].first, v = pos[j].second;
            if(u <= 0 && v <= 0 ) continue;
            if(k<=0) k = u;
            else if(k>0) h = u;
            if(h<=0) h = v;
            if(h>0){
                long long lc =(1LL*arr[k] * arr[h])/i;
                if(lc<res){
                    best.first = k;
                    best.second = h;
                    res = lc;
                }
                break;
            }
        }
    }
    cout<<min(best.first,best.second)<<" "<<max(best.first,best.second);

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    freopen("llcm.inp", "r", stdin);
    freopen("llcm.out", "w", stdout);
    // #endif
    //ll tc=1; cin>>tc;
    //for (ll t=1; t<=tc; t++) 
    solve();
    return 0;
}           