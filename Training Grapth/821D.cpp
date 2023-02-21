#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 1e6 + 7;
const ll INF = 1e9 + 7;
void solve()
{
    int n, m, k; cin>>n>>m>>k;
    int u, v;
    vector<pair<int, int>> eg(k+ 5);
    vector<int> dist(k+5, INF);
    vector<bool> check(k+ 5, false);
    int flag = 0;
    for(int  i = 1; i <= k; i++){
        cin>>eg[i].first>>eg[i].second;
        dist[i] = INF;
        if(eg[i].first ==n && eg[i].second == m) flag = 1;
    }
    if(flag == 0){
        k++;
        dist[k] = INF;
        eg[k] = {n +1, m +1};
    }
//    cout<<flag<<endl;
    queue<int>q;
    q.push(1);
    check[1] = true;
    dist[1] = 0;
    while(!q.empty())
    {
        int id = q.front();
//        cout<<id<<" ++"<<dist[id]<<endl;
        q.pop();
        u = eg[id].first, v = eg[id].second;
        check[id] = false;
        for(int i = 1; i <= k; i++){
            int dx = abs(eg[i].first - u) , dy =  abs(eg[i].second - v);
            int val = INF;

            if(dx+ dy <= 1) val = 0;
            else if(dx <= 2 || dy <= 2) val = 1;

//            if(i == k) {
//                cout<<u<<" "<<v<<" "<<eg[i].first<<" "<<eg[i].second<<" "<<val<<endl;
//            }
            if(dist[id] + val < dist[i]){
//                cout<<"YES\n";
                dist[i] = dist[id] + val;
                if(!check[i]){
                    check[i] = true;
                    q.push(i);
                }
            }
        }
//        cout<<id<<endl;
//        for(int i = 1; i <= k; i++) cout<<dist[i]<<" ";
//        cout<<endl;
    }
    if(dist[k] ==  INF) cout<<-1;
    else cout<<dist[k];


}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
