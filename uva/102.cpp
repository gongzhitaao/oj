
// Ecological Bin Packing
// Time-stamp: <2012-08-01 09:29:30 gongzhitaao>

#include <iostream>
#include <string>
using namespace std;

string info[] = { "BCG", "BGC", "CBG", "CGB", "GBC", "GCB" };
int order[][3] = {
  {0, 2, 1}, {0, 1, 2}, {2, 0, 1}, {2, 1, 0}, {1, 0, 2}, {1, 2, 0}
};
int count[6];
int bin[3][3];

int main()
{
  while (cin >> bin[0][0] >> bin[0][1] >> bin[0][2]
	 >> bin[1][0] >> bin[1][1] >> bin[1][2]
	 >> bin[2][0] >> bin[2][1] >> bin[2][2]) {

    int tot = 0;
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
	tot += bin[i][j];

    int max = 0;
    int idx = 0;
    for (int i = 0; i < 6; ++i) {
      count[i] = 0;
      for (int j = 0; j < 3; ++j)
	count[i] += bin[j][order[i][j]];
      if (count[i] > max) {
	max = count[i];
	idx = i;
      }
    }

    cout << info[idx] << ' ' << tot-max << endl;
  }
  return 0;
}
