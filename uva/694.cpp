// 694 - The Collatz Sequence
// Time-stamp: <2016-07-30 14:24:37 gongzhitaao>

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
  int A, L;
  int ncase = 1;
  while (cin >> A >> L) {
    if (A < 0 || L < 0) break;

    int len;
    long long cur;
    for (len = 0, cur = A; cur <= L; ) {
      ++len;

      if (1 == cur) break;
      if (0 == cur % 2) cur /= 2;
      else cur = 3 * cur + 1;
    }

    printf("Case %d: A = %d, limit = %d, number of terms = %d\n",
           ncase++, A, L, len);
  }
}
