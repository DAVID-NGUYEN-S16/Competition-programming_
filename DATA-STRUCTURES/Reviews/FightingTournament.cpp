/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e9+7;
const ll INF=1e5+7;
const ll MIN=- 1e5+7;
void nextLargerElement(ll arr[], ll n)
{
    vector<unordered_map<string, ll> > s;
  
    // iterating over the array
    for (ll i = 0; i < n; i++) {
        while (s.size() > 0
               && s[s.size() - 1]["value"] < arr[i]) {
            // updating the array as per the stack top
            unordered_map<string, ll> d = s[s.size() - 1];
            s.pop_back();
            arr[d["ind"]] = arr[i];
        }
        // pushing values to stack
        unordered_map<string, ll> e;
  
        e["value"] = arr[i];
        e["ind"] = i;
        s.push_back(e);
    }
  
    // updating the array as per the stack top
    while (s.size() > 0) {
        unordered_map<string, ll> d = s[s.size() - 1];
        s.pop_back();
        arr[d["ind"]] = -1;
    }
}
void solve()
{
    ll n, q; cin>>n>>q;
    vector<ll>arr(n), cur(INF), max_doan(n+5);
    // map<ll, ll>arr;
    ll next[n+5], maxx = 0, mas = 0;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        next[i] = arr[i];
        cur[arr[i]] = i;
        maxx = max(maxx, arr[i]);
        if(mas>=arr[i]) max_doan[i] = mas;
        else {
            mas = arr[i];
            max_doan[i] = mas;
        }
    }
    nextLargerElement(next, n);
    // ll mas = arr[0];
    // for(ll i=0;i<n;i++){
    //     if(mas>=arr[i]) max_doan[i] = mas;
    //     else {
    //         mas = arr[i];
    //         max_doan[i] = mas;
    //     }
    // }
    // for(ll i=0;i<n;i++) cout<<next[i]<<" ";
    // cout<<"\n";
    // for(ll i=0;i<n;i++) cout<<max_doan[i]<<" ";
    ll id, k; 
    while(q--){
        cin>>id>>k;
        id--;
        if(id>k||max_doan[id]>arr[id]){
            cout<<"0\n";
            continue;
        }
        ll cnt = 0;

        ll idnext;

        if(next[id]!=-1) idnext = cur[next[id]];
        else idnext =n;
        k-=id;
        cnt =idnext - id -1;
        if(cnt>k) cnt = k;
        if(arr[id]==maxx &&  k>cnt) {
            k = k-cnt;
            cnt+=k;
        }
        if(id!=0) cnt++;
        // else if(cnt<k)
        cout<<cnt<<"\n";

    }



}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) 
solve();
    return 0;
}