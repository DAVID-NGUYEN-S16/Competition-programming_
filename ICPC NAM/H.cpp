#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MAX = 1e6 + 7;
const long long MIN =  -1e6;
const long long MOD = 1e9 + 7;
const long long INF = 1e18 + 7;
const long long base = 31;
long long numb1[MAX], numb2[MAX], pre[MAX], pre9[MAX];
void solve()
{
    string nb1, nb2; cin>>nb1>>nb2;

    long long is = nb2.size() - nb1.size();
    for(int i = 0; i < nb2.size(); i++){
        int x = nb2[i] - '0';

        numb2[i+1] = x;
    }
    for(int i = is; i < nb2.size(); i++){
        int x = nb1[i-is] - '0';
        numb1[i+1] = x;
    }
    pre[0]=1;
    pre9[0]=1;
    for(int i = 1; i<=nb2.size(); i++) {
            pre[i] = (pre[i-1] * numb2[i]) %MOD;
            pre9[i] = (pre9[i-1] * (ll)9)%MOD;
    }
    long long k = 1;
    if(nb2.size()>nb1.size()){
        long long k = max(1,nb2[0] - '0' - 1) ;
        cout<<(k*pre9[nb2.size()-1]) % MOD<<"\n";
    }else{
        for(int i = 1; i<=nb2.size(); i++){
            if(numb2[i] - numb1[i] >= 1)
            {
                long long u = 1;
                if(i == nb2.size()) u = 0;
                //cout<<k<<"\n";
                k = (k*(numb2[i]-u))%MOD;
                cout<<(k*pre9[nb2.size() - i])%MOD<<"\n";
                //cout<<i<<" "<<k<<" "<<nb2.size() - i<<" "<<pre9[nb2.size() - i]<<" "<<numb2[i]<<endl;
                //cout<<
                return;
            }else k = (k*numb2[i])%MOD;;
        }
        cout<<k;
    }



}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    #endif
    solve();
    return 0;
}

