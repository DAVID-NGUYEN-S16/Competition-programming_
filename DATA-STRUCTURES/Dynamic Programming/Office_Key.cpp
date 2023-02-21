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
void solve(int tc = 0) {
	ll p,n,k;
	cin >> n >> k >> p;
	int a[n+5], b[k+5];
	for (ll i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	for (ll i = 0; i < k; i++) cin >> b[i];
	sort(b, b + k);
	
	const ll inf = 1e17;
	
	ll dp[k + 1][n + 1];
	for (ll i = 0; i <= k; i++) {
		for (ll j = 0; j <= n; j++) {
			dp[i][j] = inf;
		}
	}
	
	dp[0][0] = 0;
	
	for (ll i = 0; i < k; i++) {
		for (ll j = 0; j <= n; j++) {
			// don't take person
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			
			// do take person
			if (j < n) {
				dp[i + 1][j + 1] = min(dp[i + 1][j + 1], max(dp[i][j], abs(a[j] - b[i]) + abs(b[i] - p)));
			}
            cout<<dp[i + 1][j]<<" "<<dp[i + 1][j + 1]<<" "<<abs(a[j] - b[i]) + abs(b[i] - p)<<"\n";
		}
	}
	
	cout << dp[k][n] << '\n';
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