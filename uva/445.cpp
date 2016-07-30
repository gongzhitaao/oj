// 445 - Marvelous Mazes
// Time-stamp: <2016-07-29 14:25:31 gongzhitaao>

#include <iostream>
#include <string>
using namespace std;

int main()
{
  string line, maze;
  int n = 0;
  while (getline(cin, line)) {
    if (line.empty()) {
      maze += "\n";
      n = 0;
      continue;
    }

    for (char c : line) {
      if ('0' <= c && c <= '9') {
        n += c - '0';
        continue;
      }

      switch (c) {
        case 'b': c = ' '; break;
        case '!': n = 1, c = '\n'; break;
        default: /* empty */;
      }

      maze += string(n, c);
      n = 0;
    }

    maze += "\n";
  }
  cout << maze;
}
