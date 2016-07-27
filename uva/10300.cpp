// 10300 - Ecological Premium
// Time-stamp: <2016-07-26 13:49:28 gongzhitaao>

#include <cstdio>

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int f;
    scanf("%d", &f);
    int sum = 0;
    for (int j = 0; j < f; ++j) {
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      sum += a * c;
    }
    printf("%d\n", sum);
  }
}
