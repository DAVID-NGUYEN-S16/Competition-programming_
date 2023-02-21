#include<bits/stdc++.h>
using namespace std;
int cnt[150][150];
void solve()
{
    int n, k; cin>>n>>k;
    int mas = 0, x;

    for(int i = 1; i <= n; i++){
        cin>>x;
        cnt[x][i]++;
        mas = max(mas, x);
    }
    for(int i = 1; i <= k; i++){
        cin>>x;
        if( cnt[mas][x] != 0){
            cout<<"Yes\n"; return;
        }
    }
    cout<<"No\n"; return;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    solve();

}
