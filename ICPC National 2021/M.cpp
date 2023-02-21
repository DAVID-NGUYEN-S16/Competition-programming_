#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MAX = 1e6 + 7;
const long long MIN =  -1e6;
const long long MOD = 1e9 + 7;
const long long INF = 1e18 + 7;
const long long base = 31;
//int matrix[10000][10000], stand[10000][10000];
void solve()
{
    int n; cin>>n;
    int m = n + (n-1) *(n-1);
    vector<vector<int>>matrix(m, vector<int>(n, 0));
    vector<vector<int>>stand(n, vector<int>(n, 0));

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1; j++) stand[i][j] = i*(n-1) + j + n + 1;
    }
    for(int i = 0; i<n; i++) matrix[0][i] = i + 1;
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            matrix[i][j] = stand[i-1][j-1];
        }
    }
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1; j++){
                for(int k = 0; k < n-1; k++){
                    matrix[i *(n-1) + j + n][ k+1] = stand[k][(j+i*k)%(n-1)];
                }
        }
    }
    for(int i = 1; i<m; i++) matrix[i][0] = (i-1)/(n-1) + 1;
    cout<<m<<"\n";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }

}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    #endif
//    int t; cin>>t;
//	while(t--)
    solve();
    return 0;
}

