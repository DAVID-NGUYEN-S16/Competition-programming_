#include<bits/stdc++.h>
using namespace std;
int main()
{
    int cnt = 0;
    for(int i = 1; i < 123; i++){
            if(i % 3 == 1) cnt++;
    }
    cout<<cnt;

}
