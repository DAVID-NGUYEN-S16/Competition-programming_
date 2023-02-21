#include<bits/stdc++.h>
using namespace std;
const long long MAX = 1e5 + 7;
bool prefix[MAX], a[MAX];
void solve()
{
    int n, p; cin>>n>>p;
    long long x = 0;
    bool pre = false;
    for(int i = 1 ; i <= n; i++){
        cin>>x;
        if(x&1) pre = not(pre);
        prefix[i] = pre;
        a[i] = x % 2;
    }
    long long t, l, r;
    while(p--){
         cin>>t>>l>>r;
        if( t == 1){
            bool k =  r % 2;
            if( k != a[l]) {
                for(int i = l; i <= n; i++) {
                    prefix[i] = not(prefix[i]);
                }
            }
            a[l] = r % 2;
        }else{
            /*
                Thừa nhận:
                + Tổng các số từ 1 - > l  ==  tong các số từ 1 - r ( tính chẵn ,lẽ) thì chắc chắn đoạn đó thỏa
                + Thấy rằng mảng sau khi prefix
                    --> 0 1 0 0 1 0
                    thì các cặp cùng lại có thể kết hợp với nhau và đương nhiên có tổng là chẵn chỉ có
                    trường hợp chẵn và lẽ thì chắc chắn ra lẽ thì ta ko tính no
                + VÀ ở đây ta  chọn 2 vị trí l -  r trong đoạn có cùng loại đếm số lượng chúng
                ---> Sài tổ hợp (n*(n-1))/2
            */
            long long cnt_odd = 0;
            for(int i = l -1 ; i <=r ; i++)
            {
                cnt_odd += prefix[i];
            }
            long long cnt_even = (r - l + 1) - cnt_odd + 1; // tại sao + 1 ở cuối thì nhó rằng số lẽ đứng riêng 1 mik thì nó vẫn thoản mảng
            cout<<(cnt_even *(cnt_even - 1) + cnt_odd * (cnt_odd - 1))/2<<"\n";
        }
    }
}
int main()
{

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}
