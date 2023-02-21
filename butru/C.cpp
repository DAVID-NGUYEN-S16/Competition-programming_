
#include<bits/stdc++.h>
using namespace std;

const long long MAX = 1e6+ 7;
long long AB[101][101], AC[101][101], BC[101][101];
long long ABC[101][101][101];
long long A[101], B[101], C[101];
void solve()
{

    long long n; cin>>n;
    long long x, y, z;

    for(int i = 1; i <= n; i++){
        cin>>x>>y>>z;
        ABC[x][y][z] ++;
        AB[x][y] ++;
        AC[x][z] ++;
        BC[y][z] ++;
        A[x]++;
        B[y]++;
        C[z]++;
    }
    long long  ans1 = 0, ans2 = 0, ans3  =0;
    for(int i = 1; i <= 100; i++){
            if(A[i] || B[i] ||C[i]) {
                    ans1+= (A[i]*(A[i]-1)/2 + B[i]*(B[i]-1)/2 + C[i]*(C[i]-1)/2);
            }
        for(int j = 1; j <= 100; j++){
            if(AB[i][j] || AC[i][j] || BC[i][j] )
                ans2 += 2*(AB[i][j]*(AB[i][j]-1)/2 + BC[i][j]*(BC[i][j]-1)/2 + AC[i][j]*(AC[i][j]-1)/2);
            for(int h = 1; h <= 100; h++){
                if(ABC[i][j][h]*(ABC[i][j][h] - 1) >0) {
//                        cout<<i<<" + "<<j<<" + "<<h<<endl;
                        ans3+= 3*(ABC[i][j][h]*(ABC[i][j][h] - 1)/2);
                }
            }
        }
    }
    cout<<ans1-ans2+ans3;
}
int main()
{

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

