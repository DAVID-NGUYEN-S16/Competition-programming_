#include <iostream>
#include <cstring>
using namespace std;
const int mod = 1e9 + 7, N = 1e5 + 5;
int n, m, cnt, d[N];
long long f[N][35];
long long inv[N], c[35];
char s[N], a[N], T[35];

void Enter() {
    scanf("%d %d", &n, &m);
    scanf("%s%s", &s, T+1);
    int len = strlen(s);
    for(int i=0; i<len; ++i) {
        if (isdigit(s[i])) d[cnt] = d[cnt]*10 + s[i] - '0';
        else a[++cnt] = s[i];
    }
}

void Init() {
    inv[0] = inv[1] = 1;
    for(int i=2; i<=m; ++i) inv[i] = mod - mod/i * inv[mod%i] % mod;
    c[0] = 1;
}

void Process() {
    for(int i=0; i<=cnt; ++i) f[i][0] = 1;
    for(int i=1; i<=cnt; ++i) {
        // Tính tổ hợp C
        for(int j=1; j<=m; ++j) c[j] = c[j-1] * (d[i] - j + 1) % mod * inv[j] % mod;
        //  
        int dem = 0;
        long long tich = 1;
        for(int j=1; j<=m; ++j) {
            f[i][j] = f[i-1][j];
            if (T[j] == a[i]) {
                ++dem;
                for(int w=1; w<=dem; ++w) f[i][j] = (f[i][j] + f[i-1][j-w] * c[w]) % mod;
            } else dem = 0;
        }
    }
    printf("%lld", f[cnt][m]);
}

int main()
{
    freopen("password.inp","r",stdin);
    freopen("password.out","w",stdout);
    Enter();
    Init();
    Process();
}
