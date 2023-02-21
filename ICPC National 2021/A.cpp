#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MAX = 1e6 + 7;
const long long MIN =  -1e6;
const long long MOD = 1e9 + 7;
const long long INF = 1e18 + 7;
const long long base = 31;
vector<int> v[MAX];
vector<int> ans(MAX);
int n;
void process(int start, int ends, int x, int &box){
    for(int i = start ; i < ends; i++){
                    int cn = n;
                    while(cn-- && i < v[x].size()){
                        ans[v[x][i]] = box;
                        i++;
                    }
                    i--;
                    box++;
    }
}
void solve()
{
    cin>>n;
    int m = n*n;

    int arr[m+5];
    set<int> st;

    for(int i = 1; i<=m; i++) {
        cin>>arr[i];
        v[arr[i]].push_back(i);
        st.insert(arr[i]);
    }
    int box = 1;
    vector<int > du;
    for(auto x: st){
        if(v[x].size() % n ==0){
            process(0,v[x].size(), x , box);
        }else {
            int d = v[x].size() % n;
            for(int i = 0; i < d; i++){
                du.push_back(v[x][i]);
            }
            if(v[x].size()/n > 0){
                    process(d,v[x].size(), x, box );
            }
        }
    }
    for(int i = 0; i< du.size(); i++){
            int cn = n;
            while(cn-- && i < du.size()){
                    ans[du[i]] = box;
                    i++;
            }
            i--;
            box++;
    }
    cout<<"YES\n";
    for(int i = 1; i<=m; i++) cout<<ans[i]<<" ";
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
