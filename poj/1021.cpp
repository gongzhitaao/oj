/*!
  \file   1021.cpp
  \author Zhitao Gong <zzg0009@auburn.edu>
  \date   Fri Aug 30 22:39:58 2013

  \brief  2D-Nim
*/

#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int brd[2][100][100], tmp[2][10000], cnt[2], d, W, H;
unsigned int ht[2][10000];
const int dir[4][2] = {
    {-1, 0}, {0, 1}, {1, 0}, {0, -1}
};

void dfs(int i, int r, int c)
{
    tmp[0][d] = r, tmp[1][d] = c;
    ++d;
    brd[i][r][c] = -1;

    int x, y;
    for (int j = 0; j < 4; ++j) {
        x = c+dir[j][1], y = r+dir[j][0];
        if (0 <= x && x < W && 0 <= y && y < H && brd[i][y][x] > 0) {
            brd[i][y][x] = -1;
            dfs(i, y, x);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> W >> H >> n;

        memset(brd, 0, sizeof brd);
        memset(ht, 0, sizeof ht);

        for (int i = 0, x, y; i < 2; ++i) {
            cnt[i] = 0;
            for (int j = 0; j < n; ++j) {
                cin >> x >> y;
                brd[i][y][x] = 1;
            }
        }

        for (int i = 0; i < 2; ++i) {
            for (int r = 0; r < H; ++r) {
                for (int c = 0; c < W; ++c) {
                    if (brd[i][r][c] > 0) {
                        d = 0;
                        dfs(i, r, c);
                        for (int j = 0; j < d; ++j) {
                            for (int k = j+1; k < d; ++k)
                                ht[i][cnt[i]] += (tmp[0][j]-tmp[0][k])*(tmp[0][j]-tmp[0][k])
                                    + (tmp[1][j]-tmp[1][k])*(tmp[1][j]-tmp[1][k]);
                        }
                        ++cnt[i];
                    }
                }
            }
        }

        if (cnt[0] != cnt[1]) cout << "NO" << endl;
        else {
            sort(ht[0], ht[0]+cnt[0]);
            sort(ht[1], ht[1]+cnt[1]);
            bool f = true;
            for (int i = 0; i < cnt[0]; ++i) {
                if (ht[0][i] != ht[1][i]) {
                    cout << "NO" << endl;
                    f = false;
                    break;
                }
            }

            if (f) cout << "YES" << endl;
        }
    }
    return 0;
}
