// 10055 - Hashmat the Brave Warrior
// Time-stamp: <2016-07-24 15:12:59 gongzhitaao>

#include <cstdio>

int main()
{
  for (long long a, b; ~scanf("%lld %lld", &a, &b); ) {
    printf("%lld\n", a > b ? a - b : b - a);
  }
}
