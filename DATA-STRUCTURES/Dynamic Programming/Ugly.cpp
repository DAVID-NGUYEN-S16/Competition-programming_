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
/// Use Dynamic Programming.
/// Complexity O(n)
int ugly[INF];
int process(int n){
    int i2, i3, i5; 
    i2 = i3=i5=0;
    int next_multiple_of_2,next_multiple_of_3,next_multiple_of_5, ans = 0;
    ugly[0] = 1;
    next_multiple_of_2 = ugly[i2]*2;
    next_multiple_of_3 = ugly[i3]*3;
    next_multiple_of_5 = ugly[i5]*5;
    for(int i=1;i<n;i++){
        ans = min({next_multiple_of_2, next_multiple_of_3, next_multiple_of_5});
        ugly[i] = ans;
        if(ans == next_multiple_of_2){
            i2++;
            next_multiple_of_2 = ugly[i2]*2;
        }
        if(ans == next_multiple_of_3){
            i3++;
            next_multiple_of_3 = ugly[i3]*3;
        }
        if(ans == next_multiple_of_5){
            i5++;
            next_multiple_of_5 = ugly[i5]*5;
        }

    }
    return ans;

}
void solve()
{
    // memset(ugly, 1, sizeof(ugly));
    int n; cin>>n;
    cout<<process(n)<<"\n";
    // cout<<ugly[1];
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