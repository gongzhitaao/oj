/*!
  \file   125.cpp
  \author Zhitao Gong <me@gongzhitaao.org>
  \date   Fri Jun 14 22:13:43 2013

  \brief  Numbering Paths
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

    const int MAX = 30;

    int mat[MAX][MAX];
    int n, a, b, ind = 0;

    while (cin >> n) {
        for (int i = 0; i < MAX; ++i)
            for (int j = 0; j < MAX; ++j)
                mat[i][j] = 0;
        int m = 0;

        for (int i = 0; i < n; ++i) {
            cin >> a >> b;
            mat[a][b] = 1;
            if (a > m) m = a;
            if (b > m) m = b;
        }

        for (int k = 0; k <= m; ++k) {
            for (int i = 0; i <= m; ++i) {
                for (int j = 0; j <= m; ++j) {
                    if (mat[i][j] != -1) {
                        int t = mat[i][k]*mat[k][j];
                        if (0 != t &&
                            (mat[k][k] > 0 ||
                             t < 0 ||
                             -1 == mat[i][k]))
                            mat[i][j] = -1;
                        else mat[i][j] += t;
                    }
                }
            }
        }

        cout << "matrix for city " << ind++ << endl;
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j < m; ++j)
                cout << mat[i][j] << ' ';
            cout << mat[i][m] << endl;
        }
    }
    return 0;
}
