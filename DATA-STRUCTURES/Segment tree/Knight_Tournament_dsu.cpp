#include<bits/stdc++.h>
using namespace  std;
int MAX = 3E5+5;
vector<int> parent(MAX);
void dsu_init(int n){
    for(int i = 0; i <= n+1; i++) parent[i] = i;
}
int dsu_find(int x){
    if(parent[x] == x) return x;
    return parent[x] = dsu_find(parent[x]);
}
void solve() {
	int T;
	// cin >> T;
	T = 1;
	while(T--){
        int n,m; cin>>n>>m;
        vector<int> ans(n);
        dsu_init(n);
        while(m--){
            int l,r,x; cin>>l>>r>>x;
            int pos = dsu_find(l);
            while(pos <= r){
                if(pos == x){     
                    pos++;
                }
                else{
                    ans[pos-1] = x;
                    parent[pos] = pos+1;
                }
                pos = dsu_find(pos);
            }
        }
        for(auto i: ans)
            cout<<i<<' ';
    }
}
 
int32_t main()
{


    return 0;
}
