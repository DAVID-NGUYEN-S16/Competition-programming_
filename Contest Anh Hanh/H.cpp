#include<bits/stdc++.h>
using namespace std;
const long long MAX = 1e6 + 7;
void solve(){
    string a, b; cin>>a>>b;
    map<int, int> mp1, mp2;
    for(int i = 0; i < a.size(); i++){
        mp1[a[i] - '0']++;
    }
    for(int i = 0; i < b.size(); i++){
        mp2[b[i] - '0']++;
    }
    int cnt = 0;
    int diff1 = -1, diff2 = -1;
    for(int i = 0; i <= 9; i++) {
        if(mp1.count(i) !=0 && mp2.count(i) ==0) {
                cnt++;
                diff1 = i;
//                cout<<i<<"\n";
        }
        if(mp1.count(i) ==0 && mp2.count(i) !=0 ){
                diff2 = i;
                cnt++;
//                cout<<i<<"\n";
        }
    }
//    if(cnt >= 3) {
//        cout<<"nothinga";
//        return ;
//    }
    if(cnt == 0){
        cout<<"friends";
        return ;
    }
    int nb1 = 0, nb2 = 0;
    bool check = true;
    for(int i = 0; i < a.size() - 1; i++){
            check = true;
        mp1[(a[i] - '0')] --;
        mp1[(a[i+1] - '0')] --;
        if(a[i + 1] != '0' ){
            nb1 = ((a[i] - '0')+1) % 10;
            nb2 = ((a[i+1] - '0')-1);
            //cout<<nb1<<" "<<nb2<<endl;
            mp1[nb1]++;
            mp1[nb2] ++;
            for(int j = 0; j <= 9; j++) {
                if(mp1[j] !=0 && mp2[j] ==0 || mp1[j] ==0 && mp2[j] !=0 ){
                    check = false;
                }
            }
            if(check){
                cout<<"almost friends";return;
            }
            mp1[nb1] --;
            mp1[nb2] --;
        }
        check = true;
        if(a[i] != '0'  ){
                if(a[i] == '1' && i  == 0) continue;
            nb1 = ((a[i+1] - '0')+1) % 10;
            nb2 = ((a[i] - '0')-1);
            mp1[nb1]++;
            mp1[nb2] ++;
            for(int j = 0; j <= 9; j++) {
                if(mp1[j] !=0 && mp2[j] ==0 || mp1[j] ==0 && mp2[j] !=0 ){
                    check = false;
                }
            }
            if(check){
                cout<<"almost friends";return;
            }
            mp1[nb1] --;
            mp1[nb2] --;
        }
        mp1[(a[i] - '0')] ++;
        mp1[(a[i+1] - '0')] ++;
    }
    for(int i = 0; i < b.size() - 1; i++){
        mp2[(b[i] - '0')] --;
        mp2[(b[i+1] - '0')] --;
        check = true;
        if(b[i + 1] != '0' ){
            nb1 = ((b[i] - '0')+1) % 10;
            nb2 = ((b[i+1] - '0')-1);
            cout<<nb1<<" "<<nb2 <<" "<< i<<endl;
            mp2[nb1]++;
            mp2[nb2] ++;

            for(int j = 0; j <= 9; j++) {
                if(mp1[j] !=0 && mp2[j] ==0 || mp1[j] ==0 && mp2[j] !=0 ){
                    check = false;
                }
            }
            if(check){
                cout<<"almost friends";return;
            }
            mp2[nb1] --;
            mp2[nb2] --;
        }
        check = true;
        if(b[i] != '0' ){
//            cout<<nb1<<" "<<nb2<<endl;
            if(b[i] == '1' && i  == 0) continue;
            nb1 = ((b[i+1] - '0')+1) % 10;
            nb2 = ((b[i] - '0')-1);
            mp2[nb1]++;
            mp2[nb2] ++;
            for(int j = 0; j <= 9; j++) {
                if(mp1[j] !=0 && mp2[j] ==0 || mp1[j] ==0 && mp2[j] !=0 ){
                    check = false;
                }
            }
            if(check){
                cout<<"almost friends";return;
            }
            mp2[nb1] --;
            mp2[nb2] --;
        }
        mp2[(b[i] - '0')] ++;
        mp2[(b[i+1] - '0')] ++;
    }
    cout<<"nothing";

}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
//    freopen("digits.inp", "r", stdin);
//    freopen("digits.out", "w", stdout);
    solve();
}
