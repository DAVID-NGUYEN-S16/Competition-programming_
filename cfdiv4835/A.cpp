#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define debug(a) cout << #a << " = " << a << '\n'
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
#define ll long long
#define db double
#define INF 1e18
#define S second
#define F first
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
int solve()
{
    ll n;
    cin >> n;
    ll a[n+1] = {0}, zr[n+1] = {0}, one[n+1] = {0};
    ll res = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        zr[i] = zr[i-1] + (a[i]==0);
        one[i] = one[i-1] + a[i];

        if(a[i]==0)
            res += one[i-1];
    }

    ll Ans = res;
    for(int i = 1; i <= n; i++) {
        ll c = zr[n]-zr[i] - one[i-1];
        if( a[i]==0 ) {
            Ans = max(Ans, res - one[i-1] + zr[n] - zr[i]);
        }
        else
            Ans = max(Ans, res + one[i-1] - (zr[n] - zr[i]));
    }
    cout << Ans << "\n";
    return 0;
}
int main()
{
ios::sync_with_stdio(false);
cin.tie(0);
// #ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
// #endif
	long long t;
	cin >> t;
	while (t--)
    solve();
}
