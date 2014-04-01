/*!
  \file   1029.cpp
  \author Zhitao Gong <zzg0009@auburn.edu>
  \date   Thu Mar  27 09:45:52 2014

  \brief  False coin
*/

#include <cstring>
#include <iostream>
using namespace std;

int main()
{
  const int GOOD = 200;

  int N, K;
  cin >> N >> K;

  int stat[1001];
  memset(stat, 0, 1001 * sizeof(int));

  int s = 1, scale[2][500];
  for (int k = 1; k <= K; ++k) {

    int P;
    cin >> P;

    for (int i = 0; i < 2; ++i)
      for (int p = 0; p < P; ++p)
        cin >> scale[i][p];

    char c;
    cin >> c;
    if ('=' == c) {
      for (int p = 0; p < P; ++p)
        stat[scale[0][p]] = stat[scale[1][p]] = GOOD;
    } else {
      int heavy = 0, light = 1;
      if ('<' == c)
        heavy = 1, light = 0;

      // For heavy ones, we add +1 each time; for light ones, we add
      // -1 each time.
      bool flag = false;
      for (int p = 0; p < P; ++p) {
        int coin = scale[heavy][p];
        if (k - 1 == stat[coin]) stat[coin] = s, flag = true;
        else if (-(k - 1) == stat[coin]) stat[coin] = GOOD;

        coin = scale[light][p];
        if (-(k - 1) == stat[coin]) stat[coin] = -s, flag = true;
        else if (k - 1 == stat[coin]) stat[coin] = GOOD;
      }
      if (flag) ++s;
    }
  }

  int id = 0;
  for (int i = 1; i <= N; ++i) {
    if (s-1 == stat[i] || -s+1 == stat[i]) {
      if (0 == id) id = i;
      else {
        id = 0;
        break;
      }
    }
  }

  cout << id << endl;

  return 0;
}
