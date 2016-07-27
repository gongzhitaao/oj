// 490 - Rotating Sentences
// Time-stamp: <2016-07-27 16:09:36 gongzhitaao>

#include <iostream>
using namespace std;

int main()
{
  int mat[101][100];
  fill((int*)mat, (int*)mat + 101 * 100, -1);
  int row = 1, maxcol = 0;
  for (int col = 0, c; ~(c = getchar()); /* empty */) {
    if ('\n' == c) ++row, col = 0;
    else mat[row][col++] = c;
    if (col > maxcol) maxcol = col;
  }
  for (int j = 0, i; j < maxcol; ++j) {
    for (i = 1; i < row && mat[i][j] < 0; ++i) /* empty */;
    mat[i - 1][j] = 0;
    for (i = row - 1; i >= 0 && mat[i][j]; --i)
      cout << (mat[i][j] > 0 ? char(mat[i][j]) : ' ');
    cout << endl;
  }
}
