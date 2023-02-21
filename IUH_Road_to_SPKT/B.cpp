#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ll long long
const ll mod = 1e9+7;
const ll N = 2e5 + 5;
int ans = 0;

signed main() {
   int T; cin >> T; int ans  = 0;
   set<pair<pair<int,int>,int>> temp;
   while (T--){
        int n; cin >> n;
        if(n%2==1){
            cout << "-1\n";
        }
        else{
            int cnt = 0;
            for(int i = 1; i <= n; i++){
                for(int j = 1; i+j < n; j++){
                    int u = i%4;
                    int v = j%4;
                    int w = (n - i - j)%4;

                    int t = u^v^w;
                    if(t== 0) {
                            cnt++;
                            cout<<u<<" "<<v<<" "<<w<<endl;
                    }else cout<<"thua + " <<u<<" "<<v<<" "<<w<<endl;
                }
            }
            cout << cnt << "\n";
        }
   }
}


