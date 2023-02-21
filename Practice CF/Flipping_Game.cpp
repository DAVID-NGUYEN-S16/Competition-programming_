/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll INF=1e5+7;
const ll MIN=- 1e5+7;
// map<int,int>mp;
int cnt[2];
int arr[INF],l[INF], r[INF];
void solve()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        cnt[arr[i]]+=1;
        if(arr[i]==1) {
            l[i] = cnt[arr[i]];
            r[i] = cnt[0];
        }
        else{
            r[i] = cnt[arr[i]];
            l[i] = cnt[1];
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        // cout<<r[i]<<" ";
        for(int j=i;j<=n;j++){
            int sl1 = l[j] - l[i-1];
            int sl0 = r[j] - r[i-1];
            // cout<<sl1<<" "<<sl0<<" \n";
            ans = max(ans, cnt[1]-sl1+sl0);
        }
    }
    cout<<ans<<"\n";
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