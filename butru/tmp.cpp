#include<bits/stdc++.h>
using namespace std;

const long long MAX = 1e6+ 7;
void solve()
{

    long long n, x; cin>>n>>x;
    int st[n];

    for(int i = 0; i < n; i++){
        cin>>st[i];
    }
    long long sum_l = 0, sum_r = 0, cnt, p;
    int k  = n;
    for(int i = 1; i < (1<<k); i++){
        cnt = 0, p = 1;
        for(int j = 0; j < k; j++){
            if(i&(1<<j)){
                cnt++;
                p *= st[j];
            }
        }
        if(!(cnt&1) ){
            sum_l -= x/p;
        }else{
            sum_l += x/p;
        }
//        cout<<sum_l<<" "<<sum_r<<" "<<product<<" "<<r
//        <<endl;
    }
//    cout<<sum_l<<" "<<sum_r<<endl;

    cout<<sum_l;
}
int main()
{

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

