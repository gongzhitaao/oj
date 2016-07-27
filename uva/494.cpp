// 494 - Kindergarten Counting Game
// Time-stamp: <2016-07-27 14:06:34 gongzhitaao>

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
  string line;
  while (getline(cin, line)) {
    int n = 0;
    int a = ' ';
    for (char c : line) {
      if (isalpha(a) && (!isalpha(c))) ++n;
      a = c;
    }
    cout << n << endl;
  }
}
