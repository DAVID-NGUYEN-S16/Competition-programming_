#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 1e6 + 7;
const ll MOD = 998244353;
struct Matrix
{
    long long m[8][8];
};
Matrix I;
long long n;
//Matrix operator *(Matrix a, Matrix b)
//{
//    Matrix ans;
//    for(int i = 1; i <= 7; i++)
//        for(int j = 1; j <= 7; j ++) ans.m[i][j] = 0;
//    for(int i = 1; i <= 6; i++){
//        for(int j = 1; j <= 6; j++){
//            for(int k = 1; k <= 6; k++){
//                ans.m[i][j] += (a.m[i][k] * a.m[k][j]) % MOD;
//                ans.m[i][j] %= MOD;
//            }
//        }
//    }
//    return ans;
//}
Matrix operator *(Matrix a, Matrix b){
     Matrix ans;
    for(ll i=1;i<=6;i++){
        for(ll j=1;j<=6;j++){
            ans.m[i][j]=0;
        }
    }
    for(ll i=1;i<=6;i++){
        for(ll j=1;j<=6;j++){
            for(ll k=1;k<=6;k++){
                ans.m[i][j] += ((a.m[i][k]%MOD)*(b.m[k][j]%MOD))%MOD;;
                ans.m[i][j]%=MOD;
            }
        }
    }
    return ans;
}
Matrix Binpower(Matrix a, ll p){
    if(p == 1) return a;
    if(p == 0) return I;
    Matrix c = Binpower(a, p/2);
    if(p % 2 == 0) return c*c;
    else return c*c*a;
}

void solve()
{
    cin>>n;
    Matrix base, arr;
    for(int  i =1 ; i <= 6; i++){
        for(int j = 1; j <= 6; j++){
            if(i == j) I.m[i][j] = i;
            else I.m[i][j] = 0;
            base.m[i][j] = 0;
            arr.m[i][j] = 0;
        }
    }
    arr.m[1][1] = 1;
    arr.m[1][2] = 4;
    arr.m[1][3] = 2;
    arr.m[1][4] = 0;
    arr.m[1][5] = 12;
    arr.m[1][6] = 12;
    arr.m[2][1] = 1;
    arr.m[3][2] = 1;
    arr.m[4][4] = 1;
    arr.m[4][5] = 4;
    arr.m[4][6] = 2;
    arr.m[5][4] = 1;
    arr.m[6][5] = 1;

    base.m[1][1] = 12;
    base.m[2][1] = 0;
    base.m[3][1] = 0;
    base.m[4][1] = 5;
    base.m[5][1] = 1;
    base.m[6][1] = 1;

    Matrix ans = Binpower(arr, n-2);
    ans = ans*base;
//    for(int i = 1; i <= 6; i++){
//        for(int j = 1; j <= 6; j++){
//            cout<<ans.m[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    cout<<ans.m[1][1];



}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
