#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long MAX = 1e6 + 7;
const long long INF = 1e18 + 7;
const long long MOD = 1e9 + 7;
bool ch = false;
long long check(long long x, long long n){
    if( x == 1 ) {
            ch = true;
            return 0;
    }
    long long ans = 0;
    if( x % 2 == 0) return ans  = check(x /2, n) + 1;
    else if(x % 3 == 0) return ans = check( x/ 3, n) + 1;
    else return 0;
    return ans;
}
void solve()
{
//    cout<<check(18, 9);
    long long n;
    cin>>n;
    long long arr[n];
    long long gd = 0;
    for(int i = 0; i < n; i++){
            cin>>arr[i];
        gd = __gcd(gd, arr[i]);
    }
    long long cnt = 0;
    for(int i = 0 ; i < n; i++){
        arr[i]/= gd;
        long long tmp = check(arr[i], gd);
        if( ch) cnt+= tmp;
        else {
            cout<<-1; return;
        }
        ch = false;
    }
    cout<<cnt;

}
int main()
{

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
