// 414 - Machined Surfaces
// Time-stamp: <2016-07-27 14:38:26 gongzhitaao>

#include <iostream>
#include <string>

using namespace std;

int main()
{
  for (int n; (cin >> n) && n; ) {
    cin.ignore();
    int sum = 0, min = 25;
    string line;
    for (int i = 0; i < n; ++i) {
      getline(cin, line);
      int cnt = 0;
      for (char c : line)
        cnt += (' ' == c);
      sum += cnt;
      if (cnt < min) min = cnt;
    }
    cout << sum - min * n << endl;
  }
}
