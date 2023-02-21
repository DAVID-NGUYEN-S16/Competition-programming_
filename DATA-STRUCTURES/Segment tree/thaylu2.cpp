#include<bits/stdc++.h>
using namespace std;
const long long MAX = 300001;
void solve()
{

    int n; cin>>n;
    if(n%2!=0){
        for(int i = 1; i <= n; i++){
            cout<<7<<" ";

        }
    }else{
        for(int i = 1; i < n; i++) cout<<n<<" ";
        long long x = n, sum = (n-1) *n;
        for(int i = 0; i <  50;i++){
            if(x >= sum && x != n){
                cout<<x - sum;
            }
            x = x*x;
        }
    }
    cout<<endl;


}
