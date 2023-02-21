//https://open.kattis.com/problems/terracedfields?fbclid=IwAR1jKHSfc4so_NMjHkSD4E8VCWVXFEBc2X5XQfarIDRo1GBiwaJoBgW75cU
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 1e6 + 7;
ll n, sl = 0;
vector<long long> nb;
long long dp[19][100][10][2];
ll f(long long pos, long long cnt68, long long r8, bool state){
//    cout<<pos<<" "<<cnt68<<" "<<r8<<" "<<state<<endl;
    if(pos == nb.size()){
        if(cnt68 > 0 && r8 ==0) return cnt68;
        return 0;
    }
    if(dp[pos][cnt68][r8][state] != -1) return dp[pos][cnt68][r8][state] ;
    long long lmit = 0;
    if(state) lmit = 9;
    else lmit = nb[pos];
    long long res = 0;
    for(long long i = 0; i <= lmit; i++){
        long long tmp_cnt = cnt68, tmp_state = state;
        if(tmp_state == false && i < lmit) tmp_state = true;
        if(i == 6 || i == 8) tmp_cnt++;
        res+= f(pos + 1, tmp_cnt, ((r8*10)%8 + i)%8, tmp_state);
    }
//    cout<<pos<<" "<<cnt68<<" "<<r8<<" "<<state<<" :"<<res<<endl;
    return dp[pos][cnt68][r8][state] = res;
}
long long phan_ra(ll ns){
    long long x ;
    while(ns >0 ){
        x = ns%10;
        nb.push_back(x);
        if(x == 6|| x == 8) sl++;
        ns/=10;
    }
    reverse(nb.begin(), nb.end());
    memset(dp, -1, sizeof(dp));
    long long ans = f(0,0, 0, 0);

    nb.clear();
    return ans;

}

void solve()
{
    cin>>n;
    long long add = 0, ans = 0;
    ans = phan_ra(n);
    if(n % 8 !=0){
        ans+= sl;
    }
    cout<< ans<<"\n";
    sl = 0; ans = 0;


}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    long long t; cin>>t;
    while(t--)
    solve();

}

