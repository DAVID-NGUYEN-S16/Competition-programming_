
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n; cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int  j = n - 2;
    while( arr[j] < arr[j+1]) j--;
    int k = n-1;
    while(arr[j] < arr[k]) {
            k--;
    }
//    cout<<j<<" "<<k<<endl;
    swap(arr[k], arr[j]);
    reverse(arr+j+1, arr+n);
    for(int i = 0; i < n; i++)
    cout<<arr[i]<<" ";

}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();

    return 0;
}
