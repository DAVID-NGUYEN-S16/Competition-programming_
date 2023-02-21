#include<bits/stdc++.h>
using namespace std;
const long long MAX = 6e5 + 5;
const long long MOD = 1e9 + 7;

long long pres_s[MAX], sum_length[MAX];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
   // freopen("input.txt", "r", stdin);
    for(int i = 1; i < MAX; i++) pres_s[i] = pres_s[i-1] + i;
    for(int i = 1; i < MAX; i++) sum_length[i] = sum_length[i-1] + pres_s[i];
   // for(int i = 1; i < 10; i++) cout<<sum_length[i]<<" ";
    int t; cin>>t;
   //t= 0;
  // cout<<sum_length[6];
    while(t--){
        string s; cin>>s;
        int n = s.size();
        long long ans = 0;
        for(int i = 0; i < s.size(); i++){
            ans = (ans + 1LL*(s[i] - 'a' + 1) * (sum_length[n] - sum_length[n-i-1] - sum_length[i])) %MOD;
            if(i == 3) cout<<sum_length[n] <<" "<< sum_length[n-i-1] <<" "<< sum_length[i]<<"\n";
        }
        cout<<ans<<endl;
    }
}
