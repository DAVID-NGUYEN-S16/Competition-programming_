
#include<bits/stdc++.h>
using namespace std;
long long getvl(long long n, long long a, long long b){
    return (n/a)*min(a, b) + min(n%a, b-1);
}
void solve(){
    int n; cin>>n;
    vector<int>ans;
    for(int i = 1; i <= 2*n; i++){
            ans.push_back(i);
    }
    int cnt = 0;
    do{
        int s  = ans[0] * ans[1] + ans[2] * ans[3];
//        if(s == 14){
                cnt++;
            for(auto x: ans) cout<<x<<" ";
            cout<<endl;
//        }
    }while(next_permutation(ans.begin(), ans.end()));
    cout<<cnt<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
//    int t; cin>>t;
//    while(t--)
    solve();
    return 0;
}

