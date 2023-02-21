#include<bits/stdc++.h>
using namespace std;
const long long MAX = 1e7 + 5;
bool isprime[MAX];
vector<string> prime;
void san(){
    for(long long i = 2; i < MAX; i++){
        if(!isprime[i]){
            for(long long j = i * i; j < MAX; j+=i) isprime[j] = true;
        }
    }
    int cnt = 0;
    for(long long i = 2; i < ; i++){
        if(!isprime[i]) {
                //string k = to_string(i);
                prime.push_back(to_string(i));
        }
    }
}
void solve()
{

    san();
    int l, r; cin>>l>>r;

    string p; cin>>p;
    long long cnt = 0;
    for(int i = l-1; i < r; i++){

        if(prime[i].find(p) < prime[i].size()){
            cnt++;
        }
    }
    cout<<cnt;

}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie();

    solve();

}
