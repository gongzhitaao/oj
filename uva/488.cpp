// 488 - Triangle Wave
// Time-stamp: <2016-07-29 14:49:16 gongzhitaao>

#include <iostream>
#include <string>
using namespace std;

int main()
{
  int n, ampl, freq;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> ampl >> freq;

    string wave;
    for (int j = 1; j < ampl; ++j)
      wave += string(j, '0' + j) + "\n";
    for (int j = ampl; j > 0; --j)
      wave += string(j, '0' + j) + "\n";

    string waves;
    for (int j = 0; j < freq - 1; ++j)
      waves += wave + "\n";
    waves += wave;
    if (i < n - 1) waves += "\n";
    cout << waves;
  }
}
