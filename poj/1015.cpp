/*!
  \file   1015.cpp
  \author Zhitao Gong <zzg0009@auburn.edu>
  \date   Wed Aug 21 10:00:40 2013

  \brief  Jury Compromise
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int N = 201;
const int M = 21;
const int S = 20;
const int C = 801;

int s[N][M][C], a[N][M][C];
int p[N], d[N], t[M];

int main()
{
    int n, m, cnt = 0;
    while (EOF != scanf("%d %d", &n, &m)) {
        if (0 == n && 0 == m) break;

        for (int i = 1; i <= n; ++i)
            scanf("%d %d", p+i, d+i);

        memset(s, -1, sizeof s);
        int Z = S * m;
        for (int i = 0; i <= n; ++i)
            s[i][0][Z] = 0;

        memset(a, -1, sizeof a);

        int K = Z * 2;
        for (int i = 1; i <= n; ++i) {
            int J = m < i ? m : i;
            for (int j = 1; j <= J; ++j) {
                for (int k = 0; k <= K; ++k) {
                    if (s[i-1][j][k] > s[i][j][j]) {
                        s[i][j][k] = s[i-1][j][k];
                        a[i][j][k] = a[i-1][j][k];
                    }
                    int kk = k-(d[i]-p[i]);
                    if (0 <= kk && kk <= K && s[i-1][j-1][kk] != -1 &&
                        s[i-1][j-1][kk] + d[i]+p[i] > s[i][j][k]) {
                        s[i][j][k] = s[i-1][j-1][kk] + d[i]+p[i];
                        a[i][j][k] = i;
                    }
                }
            }
        }

        int l = -1;
        for (int i = 0; i <= Z; ++i) {
            l = s[n][m][Z+i] >= s[n][m][Z-i] ? Z+i : Z-i;
            if (s[n][m][l] != -1) break;
        }

        for (int j = m, i = n, k = l; j >= 1; --j) {
            t[j] = a[i][j][k];
            k -= d[t[j]] - p[t[j]];
            i = a[t[j]-1][j-1][k];
        }

        printf("Jury #%d\n"
               "Best jury has value %d for prosecution and value %d for defence:\n",
               ++cnt, (s[n][m][l]-l+Z)/2, (s[n][m][l]+l-Z)/2);

        for (int j = 1; j <= m; ++j)
            printf(" %d", t[j]);
        printf("\n");
    }
    return 0;
}
