/*!
  \file   129.cpp
  \author Zhitao Gong <me@gongzhitaao.org>
  \date   Mon Jun 17 17:47:31 2013

  \brief  Krypton Factor
*/

#include <iostream>
using namespace std;

int last_occur(const char *seq, char ch, int p)
{
    for (int i = p; i >= 0; --i)
        if (ch == seq[i]) return i;
    return -1;
}

bool repeat(const char *seq, int a, int b)
{
    if (a < b-a-1) return false;
    for (int i = b, j = a; i > a && j >= 0; --i, --j)
        if (seq[i] != seq[j]) return false;
    return true;
}

int main()
{
    int n, l;
    while (cin >> n >> l) {

        if (0 == n && 0 == l) break;

        char seq[81];
        for (int i = 0; i < 81; ++i)
            seq[i] = 'A'-1;

        int p = 0;
        for (int i = 0; i < n; ++i) {
            bool cont = true;
            while (cont) {
                for (int ch = seq[p]+1; ch < 'A'+l; ++ch) {
                    seq[p] = ch;
                    int k;
                    for (k = p-1; -1 != k && !repeat(seq, k, p); k = last_occur(seq, ch, k-1)) ;
                    if (-1 == k) {
                        ++p;
                        cont = false;
                        break;
                    }
                }
                if (cont) { seq[p--] = 'A'-1; }
            }
        }

        for (int i = 0; i < p; ++i) {
            if (i > 0 && 0 == i%64) cout << endl;
            else if (i > 0 && 0 == i%4) cout << ' ';
            cout << seq[i];
        }
        cout << endl << p << endl;
    }

    return 0;
}
