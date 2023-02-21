/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll INF=1e5+7;
const ll MIN=- 1e5+7;
void solve()
{
    int a,b; cin>>a;
    // int gia_tri_cua_bit_thap_nhat = a & ~(a-1);
    // cout<<gia_tri_cua_bit_thap_nhat;
    // // Đếm số chữ số số 0 ở đầu
    // int sl_0_first = __builtin_popcount(a);
    // cout<<"\n"<<sl_0_first<<"\n";
    // int odd_even = __builtin_parity(a);
    // cout<<odd_even<<"\n";
    for(int i = a; i>0;i=(i-1)&a) cout<<i<<" ";
}
// 0101
// 1110
// 1100 12
// 14 =  2^1 + 2^2 + 2^3
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