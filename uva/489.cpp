// 489 - Hangman Judge
// Time-stamp: <2016-07-30 14:02:04 gongzhitaao>

#include <iostream>
#include <string>
using namespace std;

int main()
{
  string target, guess;
  int exists['z' + 1];
  for (int i; (cin >> i) && i > 0; ) {
    cin >> target >> guess;

    fill(exists, exists + 'z' + 1, 0);
    int ntot = 0;
    for (char c : target) {
      if (!exists[c]) {
        ++ntot;
        exists[c] = 1;
      }
    }

    int nerr = 0, ncor = 0;
    for (char c : guess) {
      switch (exists[c]) {
        case 0: ++nerr; break;
        case 1: ++ncor; break;
      }
      exists[c] = -1;
      if (nerr >= 7 || ncor == ntot) break;
    }

    cout << "Round " << i << endl;
    if (ncor == ntot)
      cout << "You win." << endl;
    else if (nerr < 7)
      cout << "You chickened out." << endl;
    else
      cout << "You lose." << endl;
  }
}
