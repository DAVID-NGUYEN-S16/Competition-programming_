/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+7;
void solve()
{
    int n; cin>>n;
	int a[N];
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1){
	    cout<<1;
	    return ;
	}
	int cnt1=1, cnt2=1,mas = -N,ma=-N;
	set<int>s;
	a[n+1]=N;
	for(int i=2;i<=n+1;i++){
	    if(a[i]>a[i-1]){
            mas =max(cnt1, mas);
			cnt1=1;
			if(a[i-1]<=a[i]) cnt1++;
			continue;
		}
		cnt1++;
	}
// 	cout<<cnt1
	a[n+1]=1;
	for(int i=2;i<=n+1;i++){
	    if(a[i]<a[i-1]){
            ma =max(cnt2, ma);
            cnt2=1;
			// if()
// 			cout<<i<<"a\n";
			continue;
		}
		cnt2++;
	}
    int check = 0;
    for(int i=2;i<n;i++){
        if(a[i-1]<a[i] && a[i+1]<a[i]) check++;
        if(check==2){
            check=0
        }
    }
	mas = max(mas,cnt1);
// 	cout<<ma<<" "<<mas<<"\n";
    if (max(ma,mas)==0) cout<<1;
    else cout<<max(ma,mas)<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // ll tc=1; cin>>tc;
    // for (ll t=1; t<=tc; t++) 
solve();
    return 0;
}