
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll query(ll *tree,ll ss,ll se,ll qs,ll qe ,ll index)
{
	//complete overlap
	if(ss>=qs and se<=qe)
	{
		return tree[index];
	}
	//No Overlap
	if(qe<ss || qs>se)
	return 0;

	//partial overlap
	ll int mid = (ss + se)/2;
	ll int left = query(tree,ss,mid,qs,qe,2*index);
	ll int right = query(tree,mid+1,se,qs,qe,2*index+1);
	return left+right;
}
//point update
void point_update(ll  *tree, ll ss,ll se, ll i,ll inc,ll index)
{
	if(i>se || i<ss)
	return;
	if(ss == se)
	{
		tree[index] = inc;
		return;
	}
	ll int mid = (ss + se)/2;
	point_update(tree,ss,mid,i,inc,2*index);
	point_update(tree,mid+1,se,i,inc,2*index+1);
	tree[index] = tree[2*index]+tree[2*index+1];
	return;
}

void solve()
{
	int n;
	cin>>n;
	
	ll a[2*n+1];
	for(int i=0;i<2*n;i++)
	cin>>a[i];
	ll tree[4*2*n+1]={0};
	
	
	// for(int i=1;i<=4*n;i++)
	// cout<<tree[i]<<endl;
	vector<ll>ans(n+1);
	
	unordered_map<ll,ll>ump;
	for(int i=0;i<2*n;i++)
	{
		if(ump.find(a[i])!=ump.end())
		{
			int pos = ump[a[i]];
			ump.erase(a[i]);
			int nst_sg = query(tree,0,2*n-1,pos,i,1);
			ans[a[i]]  = nst_sg;
			// update with one
			point_update(tree,0,2*n-1,pos,1,1);
		}
		else
		{
			ump[a[i]] = i;
			
		}
	}
	for(int i=1;i<=n;i++)
	cout<<ans[i]<<" ";
	cout<<endl;

}
  

int main()
{
	ios_base::sync_with_stdio(false); 
    	cin.tie(NULL); 

    ll int t=1;
	 // cin>>t;
	while(t--)
	{  
      solve();
    }

	return 0;
}
