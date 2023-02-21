#include <bits/stdc++.h>

using namespace std;

int main()
{
        ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    multiset <int> S;
    multiset <int> :: iterator it;
    int n, ai;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &ai);
        S.insert(ai);
        it = S.lower_bound(ai);
        it++;
        // cout<<it<<"\n";
        if (it != S.end()) S.erase(it);
    }
    // printf("%d", S.size());
    return 0;
}