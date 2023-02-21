#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  c cout<<"yes"<<endl;
const ll MOD=1e9+7;
const ll INF=262145;
const ll MIN=- 1e5+7;
struct seg{
   int mins , maxs;
   bool check;
};
vector<seg> tree(INF*4);
ll arr[INF];
ll cnt = 0;
bool buid (int id, int l , int r){
   if(l == r){
      tree[id].mins = arr[l];
      tree[id].maxs = arr[l];
      return true;
   }
   int mid = (l+r)/2;
   if(buid(id*2+1, l, mid) == false) return false;
   if( buid(id*2+2, mid+1, r) == false) return false;
   if(tree[id * 2+1].mins > tree[id * 2+2].maxs || tree[id * 2+2].mins > tree[id * 2+1].maxs){
      tree[id].mins = min(tree[id * 2+1].mins, tree[id * 2+2].mins);
      tree[id].maxs = max(tree[id * 2+1].maxs, tree[id * 2+2].maxs);
      if(tree[id * 2+1].mins > tree[id*2+2].mins)  cnt++;
      return true;
   }else {
      return false;
   }

}

void solve()
{
   int n; cin>>n;
   int mis = n /2;
   for(int i =0; i<n; i++){
      cin>>arr[i];
   }
   if(buid(0, 0, n-1)) cout<<cnt<<"\n";
   else cout<<"-1\n";
   cnt = 0;

}

int main()
{
   ios_base::sync_with_stdio(false); cin.tie(NULL);
   // #ifndef ONLINE_JUDGE
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
   // #endif
   ll tc=1; cin>>tc;
   for (ll t=1; t<=tc; t++) 
   solve();
   return 0;
}