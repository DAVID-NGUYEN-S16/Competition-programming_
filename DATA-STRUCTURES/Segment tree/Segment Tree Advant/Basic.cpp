#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;  // giới hạn của mảng
int n;  // kích thước mảng
int t[2 * N];
void build() {  // khởi tạo cây
  for (int i = n - 1; i > 0; --i)
    t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // gán giá trị tại vị trí p
  for (t[p += n] = value; p > 1; p >>= 1)
    t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // tính tổng đoạn [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (!(r&1)) res += t[r--];
  }
  if(l==r)
    res+=t[l];
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", t + n + i);
  build();

  printf("%d\n", query(1, 3));
  return 0;
}
// Viết cho Phú Lâm
