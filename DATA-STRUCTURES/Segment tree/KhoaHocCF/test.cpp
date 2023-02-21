
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF=1e5+7;
ll glb;
ll tree[4*INF+1], a[INF];
void build_tree( ll  s,ll  e, ll  index)
{
	if(s==e)
	{
		tree[index] = a[s];
		return;
	}
	ll  mid = (s+e)/2;
	build_tree(s,mid,2*index);
	build_tree(mid+1,e,2*index+1);
	tree[index] += tree[2*index]+tree[2*index+1];
	
}

ll query(ll ss,ll se,ll & k ,ll index)
{
	if(glb!=-1||tree[index]==0)
	return INT_MAX;

	if(tree[index]<k)
	{
		k -= tree[index];
		return INT_MAX;
	}
	if(ss == se)
	{
		glb = ss;
		return ss;
	}
	//partial overlap
	ll  mid = (ss + se)/2;
	ll  left = query(ss,mid,k,2*index);
	ll  right = query(mid+1,se,k,2*index+1);
	return min(left,right);
}
//point update
void point_update(ll ss,ll se, ll i,ll inc,ll index)
{
	if(i>se || i<ss)
	return;
	if(ss == se)
	{
		tree[index] = 1- tree[index];
		return;
	}
	ll int mid = (ss + se)/2;
	point_update(ss,mid,i,inc,2*index);
	point_update(mid+1,se,i,inc,2*index+1);
	tree[index] = tree[2*index]+tree[2*index+1];
	
}
void solve()
{
	int n,q;
	cin>>n>>q;
	
	for(int i=0;i<n;i++)
	cin>>a[i];

	build_tree(0,n-1,1);

	// for(int i=1;i<=4*n;i++)
	// cout<<tree[i]<<endl;
	
	while(q--)
	{
		ll num,l;
		cin>>num>>l;
		if(num==1)
		{
			point_update(0,n-1,l,!a[l],1);
			a[l]=!a[l];
		}
		else
		{
		l++;
		glb=-1;
		ll x = query(0,n-1,l,1);
		cout<<x<<endl;
		}
		
	}

}
int main()
{
	ios_base::sync_with_stdio(false); 
    	cin.tie(NULL); 
	  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
  
    ll int t=1;
	 // cin>>t;
	while(t--)
	{  
      solve();
    }

return 0;
}
  


