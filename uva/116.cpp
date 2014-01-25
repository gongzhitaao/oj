/*!
  \file   116.cpp
  \author Zhitao Gong <me@gongzhitaao.org>
  \date   Sun Jun  9 16:29:38 2013

  \brief  Unidirectional TSP
*/

#include <iostream>
#include <string>
using namespace std;

const int ROW = 10;
const int COL = 100;

int m, n;
int mat[ROW][COL], pre[ROW][COL];
long long cost[ROW], tmp[ROW];

bool smaller(int a, int b)
{
    if (tmp[a] < tmp[b]) return true;
    if (tmp[a] == tmp[b]) return a < b;
    return false;
}

int get_min(int a, int b, int c)
{
    if (smaller(a, b)) {
        if (smaller(b, c) || smaller(a, c)) return a;
        else return c;
    } else {
        if (smaller(a, c) || smaller(b, c)) return b;
        else return c;
    }
}

int main()
{
    while (cin >> m >> n) {
        for (int r = 0; r < m; ++r)
            for (int c = n-1; c >= 0; --c)
                cin >> mat[r][c];

        if (1 == m) {
            long long t = 0;
            for (int c = 0; c < n-1; ++c) {
                t += mat[0][c];
                cout << 1 << ' ';
            }
            cout << 1 << endl << t+mat[0][n-1] << endl;
            continue;
        }

        for (int r = 0; r < m; ++r)
            cost[r] = mat[r][0];

        for (int c = 1; c < n; ++c) {

            for (int r = 0; r < m; ++r)
                tmp[r] = cost[r];

            int p = get_min(0, 1, m-1);
            pre[0][c] = p;
            cost[0] = mat[0][c] + tmp[p];

            for (int r = 1; r < m-1; ++r) {
                p = get_min(r-1, r, r+1);
                pre[r][c] = p;
                cost[r] = mat[r][c] + tmp[p];
            }

            p = get_min(0, m-2, m-1);
            pre[m-1][c] = p;
            cost[m-1] = mat[m-1][c] + tmp[p];
        }

        int idx = 0;
        for (int r = 1; r < m; ++r)
            if (cost[r] < cost[idx]) idx = r;

        int p = idx;
        cout << p+1;
        for (int c = n-1; c > 0; --c) {
            p = pre[p][c];
            cout << ' ' << p+1;
        }
        cout << endl << cost[idx] << endl;
    }
    return 0;
}
