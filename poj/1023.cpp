/*!
  \file   1023.cpp
  \author Zhitao Gong <zzg0009@auburn.edu>
  \date   Wed Sep  4 21:29:52 2013

  \brief  The Fun Number System
*/

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char fun[64], bit[64];
    int t;
    cin >> t;
    while (t-- > 0) {
        int k;
        cin >> k;
        for (int i = k - 1; i >= 0; --i)
            cin >> fun[i];

        long long n;
        cin >> n;

        memset(bit, '0', sizeof bit);

        for (int i = 0; i < k && n != 0; ++i) {
            if (0 == (n & 1)) {
                bit[i] = '0';
                n /= 2;
            }
            else {
                bit[i] = '1';
                if ('n' == fun[i]) n = (n > 0) ? (n / 2 + 1) : (n / 2);
                else n = (n > 0) ? (n / 2) : (n / 2 - 1);
            }
        }

        if (n != 0) cout << "Impossible";
        else for (int i = k - 1; i >= 0; --i) cout << bit[i];
        cout << endl;
    }
    return 0;
}
