#include<bits/stdc++.h>
using namespace std;

unsigned long long f(unsigned long long a, unsigned long long b){
    if(a == b) return 0;
    if(a > b) return f(a-b, b)* 2 + 2;
    else return f(a, b-a) * 2+ 1;
}
void solve(){
    unsigned long long a,b;
    while(cin>>a>>b){
        unsigned long long ans = 0;

        while(a != b){

            if( a > b) {
                a = a - b;
                ans =  ans *2 +2;
            }else if( a < b) {
                b = b - a;
                ans = ans * 2 + 1;
            }
            if(a == b){
                cout<<ans<<endl;
                break;
            }

        }
    }

}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
   solve();
}
