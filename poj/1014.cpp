/*!
  \file   1014.cpp
  \author Zhitao Gong <me@gongzhitaao.org>
  \date   Fri Jun 21 20:29:13 2013

  \brief  Dividing
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int cnt[7];
    int p[60001];
    int n = 0;
    while (true) {

        int sum = 0;
        for (int i = 1; i <= 6; ++i) {
            scanf("%d", cnt+i);
            sum += cnt[i] * i;
        }

        if (0 == sum) break;

        printf("Collection #%d:\n", ++n);

        if (1 == sum % 2) {
            printf("Can't be divided.\n\n");
        } else {
            sum /= 2;
            fill_n(p, sum+1, 0);
            fill_n(p, cnt[1]+1, 1);

            for (int i = 2; i <= 6; ++i) {
                if (1 == p[sum]) break;
                if (0 == cnt[i]) continue;
                int tmp = cnt[i];
                for (int k = 1; k < tmp; tmp -= k, k *= 2) {
                    for (int j = sum; j >= i*k; --j) {
                        if (1 == p[j]) continue;
                        if (1 == p[j-i*k]) {
                            p[j] = 1;
                        }
                    }
                }
                for (int j = sum; j >= i*tmp; --j) {
                    if (1 == p[j]) continue;
                    if (1 == p[j-i*tmp]) {
                        p[j] = 1;
                    }
                }
            }

            if (1 == p[sum]) printf("Can be divided.\n\n");
            else printf("Can't be divided.\n\n");
        }
    }
    return 0;
}
