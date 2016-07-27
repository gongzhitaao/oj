// 458 - The Decoder
// Time-stamp: <2016-07-27 13:52:22 gongzhitaao>

#include <iostream>
#include <string>

using namespace std;

int main()
{
  const int diff = 'J' - 'C';
  string str;
  while (getline(cin, str)) {
    for (char c : str)
      cout << char(c - diff);
    cout << endl;
  }
}
